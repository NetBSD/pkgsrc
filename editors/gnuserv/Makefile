# $NetBSD: Makefile,v 1.20 2023/09/11 21:18:49 vins Exp $

DISTNAME=	gnuserv-3.12.8
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	https://gentoo.mirror.garr.it/distfiles/f8/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.emacswiki.org/emacs/GnuClient
COMMENT=	Improved version of emacsserver for GNU Emacs

CONFLICTS+=	xemacs-[0-9]* xemacs-current-[0-9]* # bin/gnuattach; bin/gnuclient
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-x	# X support
CONFIGURE_ARGS+=	--enable-xauth	# XAUTH authentication
CONFIGURE_ARGS+=	--with-resolv	# hostname lookup
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib

EL_FILES=		devices.el gnuserv.el gnuserv-compat.el

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX} share/applications	\
			share/doc/${PKGBASE}

.PHONY: el-install doc-install

el-install:
	cd ${WRKSRC} && for FILE in ${EL_FILES}; do	\
		${INSTALL_DATA} $${FILE} $${FILE}c	\
			${DESTDIR}${EMACS_LISPPREFIX};	\
	done

doc-install:
	${INSTALL_DATA} ${WRKSRC}/README		\
	${DESTDIR}${PREFIX}/share/doc/gnuserv
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc	\
		${DESTDIR}${PREFIX}/share/doc/gnuserv

post-install: el-install doc-install
	${INSTALL_SCRIPT} ${FILESDIR}/dtemacs		\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/dtemacs.1            \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${FILESDIR}/gnuserv.desktop	\
		${DESTDIR}${PREFIX}/share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../editors/emacs/modules.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
