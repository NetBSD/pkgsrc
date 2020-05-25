# $NetBSD: Makefile,v 1.2 2020/05/25 05:18:35 rillig Exp $

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

# src/stats.cpp: In member function 'void Stats::statRead(Read*)':
# src/stats.cpp:248:29: error: array subscript has type 'char' [-Werror=char-subscripts]
#              mCycleQ30Bases[b][i]++;
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

post-install:
	${STRIP} ${DESTDIR}${PREFIX}/bin/fastp

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
