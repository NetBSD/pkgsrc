# $NetBSD: Makefile,v 1.2 2003/07/17 21:34:29 grant Exp $

DISTNAME=	gnuserv-3.12.6
CATEGORIES=	editors
MASTER_SITES=	${HOMEPAGE}/src/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://meltin.net/hacks/emacs/
COMMENT=	Improved version of emacsserver for GNU Emacs

GNU_CONFIGURE=	YES

EL_FILES=	devices.el gnuserv.el gnuserv-compat.el
post-install:
	cd ${WRKSRC} && for FILE in ${EL_FILES}; do				\
		${INSTALL_DATA} $${FILE} $${FILE}c ${EMACS_LISPPREFIX};		\
	done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
