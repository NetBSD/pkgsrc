# $NetBSD: Makefile,v 1.2 2017/09/23 19:50:09 wiedi Exp $

DISTNAME=	pcaprub-0.12.4
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pcaprub/pcaprub
COMMENT=	Ruby libpcap bindings
LICENSE=	gnu-lgpl-v2.1

MAKE_ENV.SunOS+=	cppflags="-Du_int32_t=uint32_t"

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
