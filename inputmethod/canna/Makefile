# $NetBSD: Makefile,v 1.6 2006/07/05 04:48:28 jlam Exp $

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}
PKGREVISION=	1

DEPENDS+=	Canna-server>=${CANNA_VERSION}nb2:../../inputmethod/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}nb1:../../inputmethod/canna-dict

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

CANNA_MODULE=	meta-package

do-patch:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
