# $NetBSD: Makefile,v 1.26 2020/11/06 18:04:24 maya Exp $

DISTNAME=	fonts-alee_13.3
PKGNAME=	${DISTNAME:S/fonts-alee_/alee-ttf-/1}
CATEGORIES=	fonts korean
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fonts-alee/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	https://packages.debian.org/unstable/fonts/fonts-alee
COMMENT=	A. Lee's Hangul truetype fonts
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/g}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
