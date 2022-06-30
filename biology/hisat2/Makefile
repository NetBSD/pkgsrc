# $NetBSD: Makefile,v 1.9 2022/06/30 11:18:04 nia Exp $

DISTNAME=	hisat2-2.2.1
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=DaehwanKimLab/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://ccb.jhu.edu/software/hisat2/index.shtml
COMMENT=	Alignment program for mapping next-generation sequencing reads
LICENSE=	gnu-gpl-v3

# 64-bit code, some assembly language
ONLY_FOR_PLATFORM=	*-*-x86_64

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake perl

REPLACE_BASH=		scripts/*.sh
REPLACE_PERL=		hisat2 scripts/*.sh scripts/*.pl scripts/*.py
REPLACE_PYTHON=		*.py scripts/*.py hisat2-build hisat2-inspect

PTHREAD_AUTO_VARS=	yes
WRKSRC=			${WRKDIR}/hisat2-2.2.1

# Unbreak #include <version> on case-insensitive file systems
post-patch:
	${MV} ${WRKSRC}/VERSION ${WRKSRC}/HISAT2_VERSION

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
