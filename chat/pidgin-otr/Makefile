# $NetBSD: Makefile,v 1.19 2011/11/01 06:00:47 sbd Exp $

VERSION=	3.2.0
DISTNAME=	pidgin-otr-${VERSION}
PKGREVISION=	12
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for pidgin to add OTR (Off-The-Record) encryption

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INSTALLATION_DIRS=	share/doc/pidgin-otr
USE_TOOLS+=	pkg-config perl intltool msgfmt

BUILDLINK_ABI_DEPENDS.libgcrypt+=	libgcrypt>=1.4.3
BUILDLINK_API_DEPENDS.libotr+=		libotr>=3.2.0

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pidgin-otr/

.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
