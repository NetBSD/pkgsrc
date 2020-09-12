# $NetBSD: Makefile,v 1.31 2020/09/12 10:03:22 tsutsui Exp $

DISTNAME=	VLGothic-20200720
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=vlgothic/73361/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yamajun@ofug.net
HOMEPAGE=	https://osdn.net/projects/vlgothic/
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'
LICENSE=	modified-bsd AND mplusfont

WRKSRC=		${WRKDIR}/VLGothic

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
