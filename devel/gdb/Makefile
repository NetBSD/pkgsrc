# $NetBSD: Makefile,v 1.43 2011/12/17 10:15:08 sbd Exp $
#

DISTNAME=	gdb-5.3
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends

NOT_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* NetBSD-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir

BROKEN_GETTEXT_DETECTION=	yes
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake msgfmt
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=		install install-info
TEST_TARGET=		check
INFO_FILES=		yes
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.elif ${OPSYS} == "Linux"
USE_TOOLS+=		aclocal autoheader autoconf

pre-configure:
	${RUN} cd ${WRKSRC}/gdb/gdbserver &&				\
	aclocal && autoheader && autoconf

.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
