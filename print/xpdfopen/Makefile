# $NetBSD: Makefile,v 1.2 2012/10/08 13:45:50 asau Exp $

DISTNAME=	texlive-20110705-source
PKGNAME=	xpdfopen-0.82
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Commands to control Acrobat Reader, xpdf, and evince

CONFLICTS+=	teTeX-bin<=3.0nb34
CONFLICTS+=	texlive-pdftools<2011
DEPENDS+=	web2c-[0-9]*:../../print/web2c

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/utils/xpdfopen

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xpdfopen

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
