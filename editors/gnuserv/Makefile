# $NetBSD: Makefile,v 1.6 2005/06/01 18:02:45 jlam Exp $

DISTNAME=	gnuserv-3.12.7
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${HOMEPAGE}/src/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://meltin.net/hacks/emacs/
COMMENT=	Improved version of emacsserver for GNU Emacs

CONFLICTS+=	xemacs-[0-9]*

GNU_CONFIGURE=	YES

.include "../../mk/x11.buildlink3.mk"

EL_FILES=	devices.el gnuserv.el gnuserv-compat.el
post-install:
	cd ${WRKSRC} && for FILE in ${EL_FILES}; do				\
		${INSTALL_DATA} $${FILE} $${FILE}c ${EMACS_LISPPREFIX};		\
	done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
