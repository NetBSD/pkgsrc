# $NetBSD: Makefile,v 1.5 2005/09/09 23:48:05 gdt Exp $

DISTNAME=	gaim-otr-2.0.2
PKGREVISION=	1
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for gaim to add OTR (Off-The-Record) encryption

GNU_CONFIGURE=	yes

.include "../../chat/libotr/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../chat/gaim/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
