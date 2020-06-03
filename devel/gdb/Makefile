# $NetBSD: Makefile,v 1.69 2020/06/03 16:50:19 kamil Exp $

DISTNAME=	gdb-8.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++11

BROKEN_GETTEXT_DETECTION=	yes
GNU_CONFIGURE=			yes
GNU_CONFIGURE_STRICT=		no # has sub-configures
USE_PKGLOCALEDIR=		yes
USE_LIBTOOL=			yes
USE_TOOLS+=			gmake msgfmt makeinfo perl:build bash:run
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=			install install-info
TEST_TARGET=			check
INFO_FILES=			yes
CONFIGURE_ENV+=			CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

# In gdb/configure, depcomp is parsed with sed.
SUBST_CLASSES+=			fix-depcomp
SUBST_STAGE.fix-depcomp+=	pre-configure
SUBST_MESSAGE.fix-depcomp+=	Read depcomp directly
SUBST_FILES.fix-depcomp+=	gdb/configure
SUBST_SED.fix-depcomp+=		-e 's,< ./depcomp,${_OVERRIDE_PATH.depcomp},'

CONFIGURE_ARGS+=	--disable-binutils
CONFIGURE_ARGS+=	--disable-gprof
CONFIGURE_ARGS+=	--disable-gold
CONFIGURE_ARGS+=	--disable-gas
CONFIGURE_ARGS+=	--disable-ld

CONFIGURE_ARGS+=	--enable-targets=all

AUTO_MKDIRS=		yes

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

REPLACE_BASH+=		gdb/gcore.in
REPLACE_BASH+=		sim/testsuite/sim/bfin/run-tests.sh

PLIST_VARS+=	gcore
.if (${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD" \
    || ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD")
PLIST.gcore=	yes
.endif

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.elif ${OPSYS} == "NetBSD"
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+= -with-curses
CONFIGURE_ENV+= gdb_cv_var_elf=yes
MAKE_ENV+= gdb_cv_var_elf=yes
CONFIGURE_ENV+= gdb_cv_struct_lwp=yes
MAKE_ENV+= gdb_cv_struct_lwp=yes

CONFIGURE_ARGS+=	--with-separate-debug-dir=/usr/libdata/debug
.endif

post-install:
	${RM} -f ${DESTDIR}/${PREFIX}/lib/charset.alias
#
# PATH of libiberty.a differs between clang and gcc: (and conflicts to other toolchain)
# Rename to avoid conflict to native and other toolchain
# and clang differs its path so, (the same as avr-binutils).

	(cd ${DESTDIR}${PREFIX};				\
	for d in ${MACHINE_ARCH}/libiberty.a libiberty.a;	\
	  do if [ -f lib/$$d ]; then				\
		${MV}	lib/$$d	 lib/gdb/libiberty.a;		\
		break;						\
	     fi;						\
	  done;	)

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
