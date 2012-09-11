# $NetBSD: Makefile,v 1.2 2012/09/11 23:04:25 asau Exp $
#

DISTNAME=	openfst-1.1
CATEGORIES=	math
MASTER_SITES=	http://mohri-lt.cs.nyu.edu/twiki/pub/FST/FstDownload/

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
