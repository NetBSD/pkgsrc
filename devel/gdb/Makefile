# $NetBSD: Makefile,v 1.78 2022/06/28 11:31:43 wiz Exp $

DISTNAME=	gdb-10.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c gnu++11

BROKEN_GETTEXT_DETECTION=	yes
GNU_CONFIGURE=			yes
GNU_CONFIGURE_STRICT=		no # has sub-configures
USE_PKGLOCALEDIR=		yes
USE_LIBTOOL=			yes
USE_TOOLS+=			gmake msgfmt makeinfo perl:build bash:run
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=			install-gdb install-gdbsupport
TEST_TARGET=			check
INFO_FILES=			yes
CONFIGURE_ENV+=			CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

# In gdb/configure, depcomp is parsed with sed.
SUBST_CLASSES+=			fix-depcomp
SUBST_STAGE.fix-depcomp+=	pre-configure
SUBST_MESSAGE.fix-depcomp+=	Read depcomp directly
SUBST_FILES.fix-depcomp+=	gdb/configure gdbserver/configure
SUBST_FILES.fix-depcomp+=	gdbsupport/configure
SUBST_FILES.fix-depcomp+=	gnulib/configure libctf/configure
SUBST_SED.fix-depcomp+=		-e 's,< ./depcomp,${_OVERRIDE_PATH.depcomp},'

CONFIGURE_ARGS+=	--disable-binutils
CONFIGURE_ARGS+=	--disable-gprof
CONFIGURE_ARGS+=	--disable-gold
CONFIGURE_ARGS+=	--disable-gas
CONFIGURE_ARGS+=	--disable-ld

CONFIGURE_ARGS+=	--enable-targets=all

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

REPLACE_BASH+=		gdb/gcore.in
REPLACE_BASH+=		sim/testsuite/sim/bfin/run-tests.sh

PLIST_VARS+=	gcore
.if (${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD" \
    || ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD")
PLIST.gcore=	yes
.endif

PLIST_VARS+=	gdbserver
.if ${OPSYS} == "Linux" || \
	(${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "x86_64")
INSTALL_TARGET+=	install-gdbserver
PLIST.gdbserver=	yes
.endif

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.elif ${OPSYS} == "NetBSD"
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses
CONFIGURE_ARGS+=	--with-separate-debug-dir=/usr/libdata/debug
.endif

CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/configure

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
