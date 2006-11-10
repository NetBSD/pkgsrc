# $NetBSD: Makefile,v 1.13 2006/11/10 17:57:51 perry Exp $

DISTNAME=	gnus-5.10.8
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
#PKGREVISION=	2
CATEGORIES=	mail news
MASTER_SITES=	http://www.gnus.org/dist/

MAINTAINER=	lha@NetBSD.org
HOMEPAGE=	http://www.gnus.org/
COMMENT=	Gnus is a flexible message reader running under GNU Emacs

#EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20 xemacs211 xemacs215

DEPENDS+=	digest>=20010101:../../pkgtools/digest

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/gnus
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/share/gnus
CONFIGURE_ENV+=		EMACS=${EMACS_BIN:Q}
EMACS_MODULES+=		base

# Avoid conflicting with Emacsen provided gnus info files
GNU_CONFIGURE_INFODIR=	${PREFIX}/share/doc/gnus/info

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
