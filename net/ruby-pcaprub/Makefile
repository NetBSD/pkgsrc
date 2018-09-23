# $NetBSD: Makefile,v 1.3 2018/09/23 15:55:35 taca Exp $

DISTNAME=	pcaprub-0.13.0
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pcaprub/pcaprub
COMMENT=	Ruby libpcap bindings
LICENSE=	gnu-lgpl-v2.1

MAKE_ENV.SunOS+=	cppflags="-Du_int32_t=uint32_t"

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
