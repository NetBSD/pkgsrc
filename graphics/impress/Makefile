# $NetBSD: Makefile,v 1.17 2016/02/25 13:37:47 jperkin Exp $
#

DISTNAME=	imp1.1b9
PKGNAME=	impress-1.1b9
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.ntlug.org/~ccox/impress/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://www.ntlug.org/~ccox/impress/
# AWOL, but ccox@ is listed as board member of ntlug.org
COMMENT=	WYSIWYG vector graphics application

DEPENDS+=	pstoedit>=3.19:../../graphics/pstoedit
DEPENDS+=	tcl>=8.3.2nb2:../../lang/tcl
DEPENDS+=	tk>=8.3.2nb1:../../x11/tk

WRKSRC=		${WRKDIR}/impress-1.1b9

USE_LANGUAGES=	c++

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin

BUILDLINK_TRANSFORM.SunOS+=	rm:-static

do-build:
	cd ${WRKSRC} && make make_impress make_font3d

.include "../../mk/bsd.pkg.mk"
