# $NetBSD: Makefile,v 1.32 2020/11/06 18:04:27 maya Exp $

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

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
