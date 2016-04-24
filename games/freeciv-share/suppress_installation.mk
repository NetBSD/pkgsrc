# $NetBSD: suppress_installation.mk,v 1.4 2016/04/24 06:52:44 prlw1 Exp $

# Makefile snippet to be included by freeciv-client and freeciv-server to
# prevent files installed by freeciv-share from being installed again.

CONFIGURE_ARGS+=		--without-freeciv-manual

SUBST_CLASSES+=			installmanfix
SUBST_STAGE.installmanfix=	pre-configure
SUBST_FILES.installmanfix=	Makefile.in
SUBST_SED.installmanfix+=	-e 's|translations doc ||g'
SUBST_MESSAGE.installmanfix=	Suppressing installation of man pages and localization files already in freeciv-share.

SUBST_CLASSES+=			installmanfix2
SUBST_STAGE.installmanfix2=	pre-configure
SUBST_FILES.installmanfix2=	Makefile.in
SUBST_SED.installmanfix2+=	-e 's|install-data-am: install-docDATA|install-data-am: \# install-docDATA|'
SUBST_MESSAGE.installmanfix2=	Suppressing installation of doc files already in freeciv-share

SUBST_CLASSES+=			installfix
SUBST_STAGE.installfix=		pre-configure
SUBST_FILES.installfix=		common/Makefile.in
SUBST_SED.installfix+=		-e 's|^install-exec-am: install-libLTLIBRARIES|install-exec-am: \# install-libLTLIBRARIES|'
SUBST_MESSAGE.installfix=	Suppressing installation of libs already in freeciv-share.

SUBST_CLASSES+=			installmanfix3
SUBST_STAGE.installmanfix3=	post-configure
SUBST_FILES.installmanfix3=	Makefile
SUBST_SED.installmanfix3+=	-e 's|translations doc ||g'
SUBST_MESSAGE.installmanfix3=	Suppressing installation of man pages and localization files already in freeciv-share.

SUBST_CLASSES+=			installmanfix4
SUBST_STAGE.installmanfix4=	post-configure
SUBST_FILES.installmanfix4=	Makefile
SUBST_SED.installmanfix4+=	-e 's|install-data-am: install-docDATA|install-data-am: \# install-docDATA|'
SUBST_MESSAGE.installmanfix4=	Suppressing installation of doc files already in freeciv-share

SUBST_CLASSES+=			installfix2
SUBST_STAGE.installfix2=	post-configure
SUBST_FILES.installfix2=	common/Makefile
SUBST_SED.installfix2+=		-e 's|^install-exec-am: install-libLTLIBRARIES|install-exec-am: \# install-libLTLIBRARIES|'
SUBST_MESSAGE.installfix2=	Suppressing installation of libs already in freeciv-share.
