# $NetBSD: Makefile,v 1.22 2005/04/05 11:50:25 wiz Exp $

DISTNAME=	imm36a1
PKGNAME=	imm-3.6a1
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://tonnant.itd.nrl.navy.mil/ipresearch/imm.html
COMMENT=	Internet Image(or other data) Multicaster (and receiver)

DEPENDS+=       xv>=3.10:../../graphics/xv

WRKSRC=		${WRKDIR}/${DISTNAME}.src
USE_X11=	yes
BUILD_TARGET=	netbsd

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
