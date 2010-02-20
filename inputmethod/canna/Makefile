# $NetBSD: Makefile,v 1.11 2010/02/20 10:39:01 obache Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}
PKGREVISION=	2

DEPENDS+=	Canna-server>=${CANNA_VERSION}nb2:../../inputmethod/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}nb1:../../inputmethod/canna-dict

CANNA_MODULE=	meta-package

.include "../../mk/bsd.pkg.mk"
