# $NetBSD: Makefile,v 1.1.1.1 2005/03/24 21:24:12 nathanw Exp $

DISTNAME=	libotr-2.0.1
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Library for Off-The-Record encrypted messaging

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pic

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
