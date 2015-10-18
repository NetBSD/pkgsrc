# $NetBSD: Makefile,v 1.12 2015/10/18 03:58:31 tsutsui Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}

DEPENDS+=	Canna-server>=${CANNA_VERSION}:../../inputmethod/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}:../../inputmethod/canna-dict

CANNA_MODULE=	meta-package

.include "../../mk/bsd.pkg.mk"
