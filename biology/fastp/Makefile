# $NetBSD: Makefile,v 1.1 2019/05/04 16:15:25 bacon Exp $

DISTNAME=	fastp-0.20.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenGene/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/OpenGene/fastp
COMMENT=	Ultra-fast all-in-one FASTQ preprocessor
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
BUILD_TARGET=		fastp
PTHREAD_AUTO_VARS=	yes

post-install:
	${STRIP} ${DESTDIR}${PREFIX}/bin/fastp

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
