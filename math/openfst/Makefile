# $NetBSD: Makefile,v 1.7 2022/10/11 16:35:49 nros Exp $

DISTNAME=	openfst-1.8.2
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.openfst.org/
COMMENT=	Library for manipulating transducers
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++17
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
GCC_REQD+=	8 # needs <charconv> for from_chars

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}
.include "../../mk/bsd.pkg.mk"
