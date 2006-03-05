# $NetBSD: Makefile,v 1.11 2006/03/05 16:27:26 jlam Exp $

DISTNAME=	gnus-5.10.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://quimby.gnus.org/gnus/dist/

MAINTAINER=	lha@NetBSD.org
HOMEPAGE=	http://www.gnus.org/
COMMENT=	Gnus is a flexible message reader running under GNU Emacs

#EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20 xemacs211 xemacs215

DEPENDS+=	digest>=20010101:../../pkgtools/digest

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/gnus
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/share/gnus
# Avoid conflicting with Emacsen provided gnus info files
CONFIGURE_ARGS+=	--infodir=${PREFIX}/share/doc/gnus/info

USE_TOOLS+=		makeinfo
INFO_DIR=		share/doc/gnus/info
INFO_FILES=		emacs-mime gnus message pgg sieve

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
