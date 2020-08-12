# $NetBSD: Makefile,v 1.2 2020/08/12 00:18:27 brook Exp $

GITHUB_PROJECT=	fastflow
GITHUB_TAG=	3.0.0
DISTNAME=	3.0.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fastflow/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastflow/fastflow/
COMMENT=	High performance C++ parallel building blocks
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash pax
NO_BUILD=	yes

REPLACE_BASH+=	ff/mapping_string.sh
REPLACE_BASH+=	tests/runtests.sh

INSTALLATION_DIRS+=	include/ff

do-install:
	cd ${WRKSRC} && ${PAX} -rw ff ${DESTDIR}${PREFIX}/include
	${CHMOD} -R go-w ${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
