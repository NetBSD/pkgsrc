# $NetBSD: Makefile,v 1.5.10.1 2014/02/09 23:19:22 tron Exp $
#

DISTNAME=	yaml-0.1.5
PKGNAME=	lib${DISTNAME}
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
