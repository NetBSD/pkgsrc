# $NetBSD: Makefile,v 1.2 2018/12/06 19:41:08 leot Exp $

DISTNAME=	json-yaml-1.1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/sjmulder/json-yaml/
COMMENT=	Convert JSON to YAML
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
