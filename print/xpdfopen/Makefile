# $NetBSD: Makefile,v 1.5 2015/12/12 19:23:59 markd Exp $

DISTNAME=	texlive-20150521-source
PKGNAME=	xpdfopen-0.86
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
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
