# $NetBSD: Makefile,v 1.32 2012/10/03 21:54:03 wiz Exp $

DISTNAME=	pidgin-otr-4.0.0
PKGREVISION=	4
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for pidgin to add OTR (Off-The-Record) encryption

GNU_CONFIGURE=	yes
INSTALLATION_DIRS=	share/doc/pidgin-otr
USE_TOOLS+=	pkg-config perl intltool msgfmt

BUILDLINK_ABI_DEPENDS.libgcrypt+=	libgcrypt>=1.4.3

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pidgin-otr/

.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
