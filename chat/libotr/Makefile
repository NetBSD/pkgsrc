# $NetBSD: Makefile,v 1.4 2006/02/05 23:08:25 joerg Exp $

DISTNAME=	libotr-2.0.2
PKGREVISION=	1
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Library for Off-The-Record encrypted messaging

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pic

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
