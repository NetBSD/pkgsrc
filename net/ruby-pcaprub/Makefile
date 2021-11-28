# $NetBSD: Makefile,v 1.5 2021/11/28 08:02:29 taca Exp $

DISTNAME=	pcaprub-0.13.1
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pcaprub/pcaprub
COMMENT=	Ruby libpcap bindings
LICENSE=	gnu-lgpl-v2.1

MAKE_ENV.SunOS+=	cppflags="-Du_int32_t=uint32_t"

RUBY_VERSIONS_INCOMPATIBLE=	30

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
