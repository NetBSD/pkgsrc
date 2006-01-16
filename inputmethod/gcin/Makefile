# $NetBSD: Makefile,v 1.1.1.1 2006/01/16 13:01:16 rxg Exp $
#

DISTNAME=		gcin-1.1.5
CATEGORIES=		inputmethod
MASTER_SITES=		http://www.csie.nctu.edu.tw/~cp76/gcin/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://www.csie.nctu.edu.tw/~cp76/gcin/
COMMENT=		Gtk Chinese INput application in X

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--x11base=${X11BASE:Q}
CONFIGURE_ARGS+=	--use_xim=Y
CONFIGURE_ARGS+=	--new_gtk_im=Y
USE_TOOLS+=		gmake
USE_TOOLS+=		pkg-config

REPLACE_INTERPRETER+=	sh
_REPLACE.sh.old=	/bin/bash
_REPLACE.sh.new=	${SH:Q}
_REPLACE_FILES.sh=	configure
_REPLACE_FILES.sh+=	scripts/gcin-user-setup
_REPLACE_FILES.sh+=	scripts/gcin-utf8-setup
_REPLACE_FILES.sh+=	scripts/modify-XIM
_REPLACE_FILES.sh+=	scripts/utf8-edit

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
