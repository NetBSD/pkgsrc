# $NetBSD: Makefile,v 1.15 2012/10/03 11:43:34 asau Exp $

DISTNAME=	gnuserv-3.12.7
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
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
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	cd ${WRKSRC} && for FILE in ${EL_FILES}; do				\
		${INSTALL_DATA} $${FILE} $${FILE}c ${DESTDIR}${EMACS_LISPPREFIX};		\
	done

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX}/lib
.endif

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
