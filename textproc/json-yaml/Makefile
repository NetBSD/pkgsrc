# $NetBSD: Makefile,v 1.1 2018/09/22 07:24:10 maya Exp $

GITHUB_PROJECT=	json-yaml
DISTNAME=	1.1.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/sjmulder/json-yaml/
COMMENT=	Convert JSON to YAML
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/json-yaml-1.1.1

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
