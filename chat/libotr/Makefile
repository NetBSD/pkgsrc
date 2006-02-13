# $NetBSD: Makefile,v 1.5 2006/02/13 14:44:31 salo Exp $

DISTNAME=	libotr-3.0.0
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Library for Off-The-Record encrypted messaging

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pic

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
