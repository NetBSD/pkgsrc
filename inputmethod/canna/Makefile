# $NetBSD: Makefile,v 1.9 2008/09/18 12:35:27 taca Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}
PKGREVISION=	2

DEPENDS+=	Canna-server>=${CANNA_VERSION}nb2:../../inputmethod/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}nb1:../../inputmethod/canna-dict

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
PLIST_SRC=	# empty (meta-package)

CANNA_MODULE=	meta-package

do-patch:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
