# $NetBSD: Makefile,v 1.3 2017/05/03 08:38:41 jperkin Exp $
#

DISTNAME=	open-vcdiff-0.8.3
CATEGORIES=	devel
MASTER_SITES=	http://open-vcdiff.googlecode.com/files/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/open-vcdiff/
COMMENT=	RFC 3284 encoder/decoder for VCDIFF Differencing and Compression
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++11

AUTO_MKDIRS=	yes

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-error=c++11-narrowing
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
