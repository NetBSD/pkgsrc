# $NetBSD: Makefile,v 1.3 2003/07/17 21:46:12 grant Exp $

DISTNAME=	gnus-5.10.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://quimby.gnus.org/gnus/dist/

MAINTAINER=	lha@NetBSD.org
HOMEPAGE=	http://www.gnus.org/
COMMENT=	Gnus is a flexible message reader running under GNU Emacs

#EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20 xemacs211 xemacs215

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/gnus
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/share/gnus
# Avoid conflicting with Emacsen provided gnus info files
CONFIGURE_ARGS+=	--infodir=${PREFIX}/share/doc/gnus/info

USE_NEW_TEXINFO=	YES
USE_MAKEINFO=		YES
INFO_DIR=		share/doc/gnus/info
INFO_FILES=		emacs-mime gnus message pgg sieve

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
