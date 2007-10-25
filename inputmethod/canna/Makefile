# $NetBSD: Makefile,v 1.7 2007/10/25 22:00:46 jlam Exp $

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}
PKGREVISION=	1

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
