# $NetBSD: Makefile,v 1.30 2019/04/04 08:21:11 maya Exp $

DISTNAME=	VLGothic-20141206
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=vlgothic/62375/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yamajun@ofug.net
#HOMEPAGE=	http://vlgothic.dicey.org/
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'
LICENSE=	modified-bsd AND mplusfont

WRKSRC=		${WRKDIR}/VLGothic

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
