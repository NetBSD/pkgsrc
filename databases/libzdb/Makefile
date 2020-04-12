# $NetBSD: Makefile,v 1.20 2020/04/12 08:27:50 adam Exp $

DISTNAME=	libzdb-3.1
PKGREVISION=	14
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	https://www.tildeslash.com/libzdb/
COMMENT=	Zild Database Library, a fast thread-safe connection pooling library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	zdb.pc.in

SUBST_CLASSES+=		ossl
SUBST_STAGE.ossl=	pre-configure
SUBST_MESSAGE.ossl=	fix openssl configure test usage of deprecated symbol
SUBST_FILES.ossl=	configure
SUBST_SED.ossl=		-e 's,SSL_library_init,SSL_CTX_new,g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
