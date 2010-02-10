# $NetBSD: Makefile,v 1.27 2010/02/10 18:11:45 joerg Exp $

DISTNAME=	imm36a1
PKGNAME=	imm-3.6a1
PKGREVISION=	1
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://tang.itd.nrl.navy.mil/5522/ntm/imm.html
COMMENT=	Internet Image(or other data) Multicaster (and receiver)

BROKEN=		Depends on TCL/TK 8.3

DEPENDS+=	xv>=3.10:../../graphics/xv

WRKSRC=		${WRKDIR}/${DISTNAME}.src
BUILD_TARGET=	netbsd

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
