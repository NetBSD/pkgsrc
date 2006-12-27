# $NetBSD: Makefile,v 1.9 2006/12/27 13:37:38 joerg Exp $
#

DISTNAME=		gcin-1.1.7
PKGREVISION=		1
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
USE_TOOLS+=		pkg-config gmake
GTK2_IMMODULES=		yes

REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		/bin/bash
REPLACE.sh.new=		${SH}
REPLACE_FILES.sh=	configure
REPLACE_FILES.sh+=	scripts/gcin-user-setup
REPLACE_FILES.sh+=	scripts/modify-XIM
REPLACE_FILES.sh+=	scripts/utf8-edit

.include "../../x11/gtk2/modules.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
