# $NetBSD: Makefile,v 1.5 2008/05/30 12:29:00 wiz Exp $

VERSION=	3.1.0
PKGREVISION=	3
DISTNAME=	pidgin-otr-${VERSION}
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for pidgin to add OTR (Off-The-Record) encryption

GNU_CONFIGURE=	yes
INSTALLATION_DIRS=	share/doc/pidgin-otr
USE_TOOLS+=	pkg-config perl intltool msgfmt

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pidgin-otr/

.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
