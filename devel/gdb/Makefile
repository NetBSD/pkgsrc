# $NetBSD: Makefile,v 1.6 2003/03/10 23:50:48 seb Exp $
#

DISTNAME=       gdb-5.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	symbolic debugger for multiple language frontends

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/bfd/libtool ${WRKSRC}/opcodes/libtool
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=	install install-info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
