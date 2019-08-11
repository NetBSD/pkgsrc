# $NetBSD: Makefile,v 1.3 2019/08/11 13:18:00 wiz Exp $

DISTNAME=	hisat2-2.1.0.23
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=infphilo/}
GITHUB_TAG=	20f333e2cfe7ff4d1362b248912893e2644683d7

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://ccb.jhu.edu/software/hisat2/index.shtml
COMMENT=	Alignment program for mapping next-generation sequencing reads
LICENSE=	gnu-gpl-v3

# 64-bit code, some assembly language
ONLY_FOR_PLATFORM=	*-*-x86_64

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake perl

REPLACE_BASH=		hisatgenotype_scripts/*.sh
REPLACE_PERL=		hisat2 scripts/*.sh scripts/*.pl
REPLACE_PYTHON=		*.py hisat2-build hisat2-inspect
REPLACE_PYTHON+=	hisatgenotype_modules/*.py hisatgenotype_scripts/*.py

MAKE_FILE=		${FILESDIR}/Makefile.pkg
PTHREAD_AUTO_VARS=	yes

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
