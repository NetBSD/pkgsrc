# $NetBSD: Makefile,v 1.49 2015/04/25 14:20:28 tnn Exp $

VERSION=	4.0.1
DISTNAME=	pidgin-otr-${VERSION}
PKGNAME=	pidgin-otr-${VERSION}
PKGREVISION=	1
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Plugin for pidgin to add OTR (Off-The-Record) encryption

LICENSE=	gnu-gpl-v2

# Work around rc tarballs that unpack to bare version.
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt perl pkg-config
INSTALLATION_DIRS+=	share/doc/pidgin-otr

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
