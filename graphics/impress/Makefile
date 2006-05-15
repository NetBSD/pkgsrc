# $NetBSD: Makefile,v 1.11 2006/05/15 21:44:22 joerg Exp $
#

DISTNAME=	imp1.1b9
PKGNAME=	impress-1.1b9
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.ntlug.org/~ccox/impress/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.ntlug.org/~ccox/impress/
COMMENT=	WYSIWYG vector graphics application

DEPENDS+=	pstoedit>=3.19:../../graphics/pstoedit
DEPENDS+=	tcl>=8.3.2nb2:../../lang/tcl
DEPENDS+=	tk>=8.3.2nb1:../../x11/tk

WRKSRC=		${WRKDIR}/impress-1.1b9

USE_LANGUAGES=	c++

do-build:
	cd ${WRKSRC} && make make_impress make_font3d

.include "../../mk/bsd.pkg.mk"
