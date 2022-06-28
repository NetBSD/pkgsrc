# $NetBSD: Makefile,v 1.4 2022/06/28 11:30:59 wiz Exp $

DISTNAME=	bowtie2-2.4.4
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=BenLangmead/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/BenLangmead/bowtie2
COMMENT=	Ultrafast, memory-efficient short read aligner
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax:build perl:run
REPLACE_PERL=	scripts/*.pl bowtie2
REPLACE_PYTHON=	bowtie2-build bowtie2-inspect
REPLACE_SH=	scripts/bowtie2-hbb.sh

DATADIR=	${PREFIX}/share/bowtie2
EXAMPLESDIR=	${PREFIX}/share/examples/bowtie2

INSTALLATION_DIRS=	share/bowtie2/scripts share/examples/bowtie2

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.sh ${WRKSRC}/scripts/*.pl \
		${DESTDIR}${DATADIR}/scripts
	(cd ${WRKSRC}/example && pax -rw index reads reference \
		${DESTDIR}${EXAMPLESDIR})

.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
