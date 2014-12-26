# $NetBSD: Makefile,v 1.3 2014/12/26 23:53:08 mef Exp $
#

DISTNAME=	openfst-1.1
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.openfst.org/
COMMENT=	OpenFst is a library for manipulating transducers
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../mk/bsd.pkg.mk"
