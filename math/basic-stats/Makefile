# $NetBSD: Makefile,v 1.1 2022/06/12 14:35:09 bacon Exp $

DISTNAME=	basic-stats-0.1.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/basic-stats
COMMENT=	Command-line tool to perform basic statistics on tabular data
LICENSE=	2-clause-bsd

INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend

.include "../../devel/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
