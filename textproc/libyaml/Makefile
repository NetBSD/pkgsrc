# $NetBSD: Makefile,v 1.11 2018/07/06 06:50:40 adam Exp $

DISTNAME=	yaml-0.2.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyyaml.org/wiki/LibYAML
COMMENT=	YAML 1.1 parser and emitter written in C
LICENSE=	mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	yaml-0.1.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
