# $NetBSD: Makefile,v 1.13 2020/05/10 03:56:40 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	xpdfopen-0.86
PKGREVISION=	6
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Commands to control Acrobat Reader, xpdf, and evince

DEPENDS+=	web2c-[0-9]*:../../print/web2c

EXTRACT_ELEMENTS+=	${DISTNAME}/utils/xpdfopen

WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xpdfopen

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
