# $NetBSD: Makefile,v 1.1.1.1 2003/06/08 05:46:34 epg Exp $

DISTNAME=	gnuserv-3.12.6
CATEGORIES=	editors
MASTER_SITES=	${HOMEPAGE}/src/

MAINTAINER=	epg@netbsd.org
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
