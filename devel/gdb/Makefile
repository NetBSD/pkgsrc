# $NetBSD: Makefile,v 1.17 2004/04/26 06:05:24 snj Exp $
#

DISTNAME=       gdb-5.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=	install install-info
TEST_TARGET=	check
INFO_FILES=		bfd.info gdb.info gdbint.info mmalloc.info stabs.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
