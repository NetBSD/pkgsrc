# $NetBSD: Makefile,v 1.7 2023/09/09 10:27:20 mef Exp $

DISTNAME=		emacs-jabber-0.8.92
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=emacs-jabber/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		aran@100acres.us
HOMEPAGE=		http://emacs-jabber.sourceforge.net/
COMMENT=		Jabber client for Emacs
LICENSE=		gnu-gpl-v2 # or later

GNU_CONFIGURE=		yes
INFO_FILES=		YES

CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}
CONFIGURE_ARGS+=	--without-gconf
CONFIGURE_ARGS+=	--disable-schemas-install
CONFIGURE_ENV+=		EMACS=${EMACS_BIN}

TEST_TARGET=		check

# net-utils, mule-ucs for xemacs
EMACS_MODULES=		base
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
