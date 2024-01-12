# $NetBSD: Makefile,v 1.36 2024/01/12 16:12:10 tsutsui Exp $

DISTNAME=	VLGothic-20230918
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	https://vlgothic.dicey.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yamajun@ofug.net
HOMEPAGE=	https://vlgothic.dicey.org/
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'
LICENSE=	modified-bsd AND mplusfont

WRKSRC=		${WRKDIR}/VLGothic

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
