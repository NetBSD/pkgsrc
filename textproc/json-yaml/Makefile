# $NetBSD: Makefile,v 1.6 2025/12/19 14:21:11 sjmulder Exp $

DISTNAME=	json-yaml-1.2.2
CATEGORIES=	textproc
MASTER_SITES=	https://codeberg.org/sjmulder/json-yaml/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://codeberg.org/sjmulder/json-yaml/
COMMENT=	Convert JSON to YAML and back
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
