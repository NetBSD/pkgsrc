# $NetBSD: Makefile,v 1.11 2019/05/09 09:47:36 adam Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	xpdfopen-0.86
PKGREVISION=	5
CATEGORIES=	print

HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Commands to control Acrobat Reader, xpdf, and evince

DEPENDS+=	web2c-[0-9]*:../../print/web2c

EXTRACT_ELEMENTS+=	${DISTNAME}/utils/xpdfopen

WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xpdfopen

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
