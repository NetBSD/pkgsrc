# $NetBSD: Makefile,v 1.32 2011/12/11 21:02:29 marino Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

CONFLICTS+=	emacs-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs/files
PATCHDIR=	${.CURDIR}/../../editors/emacs/patches
PKGDIR=		${.CURDIR}/../../editors/emacs

.include "../../editors/emacs/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf \
			--without-rsvg --without-x --without-xft \
			--without-gif --without-jpeg --without-png \
			--without-tiff --without-xpm

##  Update emacs.desktop to launch emacs-nox11 in Terminal
SUBST_CLASSES+=		term
SUBST_STAGE.term=	post-patch
SUBST_MESSAGE.term=	Enabling desktop launch in Terminal 
SUBST_FILES.term=	etc/emacs.desktop
SUBST_SED.term=		-e 's,^Terminal=.*,Terminal=true,'

.include "../../mk/bsd.pkg.mk"
