# $NetBSD: Makefile,v 1.10 2026/01/14 10:54:01 wiz Exp $

DISTNAME=	openfst-1.8.2
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://www.openfst.org/twiki/bin/view/FST/WebHome
COMMENT=	Library for manipulating transducers
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

USE_CXX_FEATURES+=	c++17 charconv

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
