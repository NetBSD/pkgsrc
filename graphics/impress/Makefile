# $NetBSD: Makefile,v 1.9 2005/01/08 18:34:08 minskim Exp $
#

DISTNAME=	imp1.1b9
PKGNAME=	impress-1.1b9
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ntlug.org/~ccox/impress/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.ntlug.org/~ccox/impress/
COMMENT=	WYSIWYG vector graphics application

DEPENDS+=	pstoedit>=3.19:../../graphics/pstoedit
DEPENDS+=	tcl>=8.3.2nb2:../../lang/tcl
DEPENDS+=	tk>=8.3.2nb1:../../x11/tk

WRKSRC=		${WRKDIR}/impress-1.1b9

do-build:
	cd ${WRKSRC} && make make_impress make_font3d

.include "../../mk/bsd.pkg.mk"
