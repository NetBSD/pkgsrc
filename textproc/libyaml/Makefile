# $NetBSD: Makefile,v 1.9 2014/12/20 21:04:32 wiz Exp $

DISTNAME=	yaml-0.1.6
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyyaml.org/wiki/LibYAML
COMMENT=	YAML 1.1 parser and emitter written in C
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	yaml-0.1.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
