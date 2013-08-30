# $NetBSD: Makefile,v 1.6 2013/08/30 20:16:53 asau Exp $

DISTNAME=	munge-0.5.10
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://munge.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://code.google.com/p/munge/
COMMENT=	Authentication service for creating and validating credentials

USE_TOOLS=	perl
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--localstatedir=$(VARBASE)

OWN_DIRS=	$(VARBASE)/lib/munge $(VARBASE)/log/munge $(VARBASE)/run/munge

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
