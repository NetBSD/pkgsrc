# $NetBSD: Makefile,v 1.5 2005/01/31 00:10:12 minskim Exp $

DISTNAME=	gnuserv-3.12.7
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${HOMEPAGE}/src/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://meltin.net/hacks/emacs/
COMMENT=	Improved version of emacsserver for GNU Emacs

CONFLICTS+=	xemacs-[0-9]*

GNU_CONFIGURE=	YES
USE_X11=	YES

EL_FILES=	devices.el gnuserv.el gnuserv-compat.el
post-install:
	cd ${WRKSRC} && for FILE in ${EL_FILES}; do				\
		${INSTALL_DATA} $${FILE} $${FILE}c ${EMACS_LISPPREFIX};		\
	done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
