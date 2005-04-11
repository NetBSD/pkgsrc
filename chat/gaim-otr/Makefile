# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:03 tv Exp $

DISTNAME=	gaim-otr-2.0.1
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for gaim to add OTR (Off-The-Record) encryption

USE_GNU_TOOLS=	make

.include "../../chat/libotr/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../chat/gaim/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
