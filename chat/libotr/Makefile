# $NetBSD: Makefile,v 1.3 2005/07/27 19:17:35 gdt Exp $

DISTNAME=	libotr-2.0.2
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Library for Off-The-Record encrypted messaging

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pic

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
