# $NetBSD: Makefile,v 1.2 2022/06/30 11:18:04 nia Exp $

PKGNAME=	filter-fastq-0.0.0.20210527
PKGREVISION=	1
GITHUB_PROJECT=	filter-fastq
GITHUB_TAG=	d2c9218
DISTNAME=	filter-fastq
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=stephenfloor/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stephenfloor/filter-fastq/
COMMENT=	Filter reads from a FASTQ file
LICENSE=	mit

WRKSRC=		${WRKDIR}/filter-fastq-d2c92182674a6d5aa257fb63eb60ac24ddb8b4a0
USE_LANGUAGES=	# none
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	27

REPLACE_PYTHON+=	filter_fastq.py

INSTALLATION_DIRS+=	bin share/doc/filter_fastq

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/filter_fastq.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/filter_fastq

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
