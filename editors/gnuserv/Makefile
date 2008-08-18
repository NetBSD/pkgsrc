# $NetBSD: Makefile,v 1.10 2008/08/18 00:55:48 epg Exp $

DISTNAME=	gnuserv-3.12.7
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${HOMEPAGE}/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://meltin.net/hacks/emacs/
COMMENT=	Improved version of emacsserver for GNU Emacs

CONFLICTS+=	xemacs-[0-9]*

GNU_CONFIGURE=	YES

.include "../../x11/libXau/buildlink3.mk"

EL_FILES=	devices.el gnuserv.el gnuserv-compat.el
post-install:
	cd ${WRKSRC} && for FILE in ${EL_FILES}; do				\
		${INSTALL_DATA} $${FILE} $${FILE}c ${EMACS_LISPPREFIX};		\
	done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
