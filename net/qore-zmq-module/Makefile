# $NetBSD: Makefile,v 1.4 2023/10/24 22:10:31 wiz Exp $

DISTNAME=	qore-zmq-module-1.0.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/module-zmq/releases/download/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://qore.org/
COMMENT=	Qore ZeroMQ module
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_USE_GNU_INSTALL_DIRS=	no

.include "../../lang/qore/module.mk"

.include "../../devel/cmake/build.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../net/czmq/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
