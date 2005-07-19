# $NetBSD: Makefile,v 1.5 2005/07/19 10:17:17 grant Exp $
#
.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}

DEPENDS+=	Canna-server>=${CANNA_VERSION}:../../inputmethod/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}:../../inputmethod/canna-dict

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

CANNA_MODULE=	meta-package

do-patch:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
