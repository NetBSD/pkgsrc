# $NetBSD: Makefile,v 1.1.1.1 2007/08/02 11:42:21 gdt Exp $

VERSION=	3.1.0
DISTNAME=	pidgin-otr-${VERSION}
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for pidgin to add OTR (Off-The-Record) encryption

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config perl intltool

.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
