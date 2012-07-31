# $NetBSD: suppress_installation.mk,v 1.1 2012/07/31 15:49:37 prlw1 Exp $

# Makefile snippet to be included by freeciv-client and freeciv-server to
# prevent files installed by freeciv-share from being installed again.

SUBST_CLASSES+=			installmanfix
SUBST_STAGE.installmanfix=	pre-configure
SUBST_FILES.installmanfix=	Makefile.in
SUBST_SED.installmanfix+=	-e 's|po doc||g'
SUBST_MESSAGE.installmanfix=	Suppressing installation of man pages and localization files already in freeciv-share.

SUBST_CLASSES+=			installfix
SUBST_STAGE.installfix=		pre-configure
SUBST_FILES.installfix=		common/Makefile.in
SUBST_SED.installfix+=		-e 's|^install-exec-am: install-libLTLIBRARIES|install-exec-am: \# install-libLTLIBRARIES|'
SUBST_MESSAGE.installfix=	Suppressing installation of libs already in freeciv-share.
