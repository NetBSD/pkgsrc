# $NetBSD: Makefile,v 1.10 2006/06/20 22:28:01 joerg Exp $

DISTNAME=	gaim-otr-3.0.0
PKGREVISION=	1
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for gaim to add OTR (Off-The-Record) encryption

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../chat/gaim/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
