# $NetBSD: Makefile,v 1.23 2005/12/05 20:50:04 rillig Exp $
#

DISTNAME=       gdb-5.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends

NOT_FOR_PLATFORM=	Darwin-*-*

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=	install install-info
TEST_TARGET=	check
INFO_FILES=		bfd.info gdb.info gdbint.info mmalloc.info stabs.info
CONFIGURE_ENV+=         CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
