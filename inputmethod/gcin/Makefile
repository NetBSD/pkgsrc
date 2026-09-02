# $NetBSD: Makefile,v 1.58 2026/09/02 19:03:03 wiz Exp $
#

DISTNAME=		gcin-1.1.7
PKGREVISION=		44
CATEGORIES=		inputmethod
#MASTER_SITES=		http://www.csie.nctu.edu.tw/~cp76/gcin/download/
MASTER_SITES=		http://cle.linux.org.tw/gcin/download/gcin-old/gcin-1.1.x/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rxg@NetBSD.org
#HOMEPAGE=		http://www.csie.nctu.edu.tw/~cp76/gcin/
COMMENT=		Gtk Chinese INput application in X

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--x11base=${X11BASE:Q}
CONFIGURE_ARGS+=	--use_xim=Y
CONFIGURE_ARGS+=	--new_gtk_im=Y
USE_TOOLS+=		pkg-config gmake
GTK2_IMMODULES=		yes
.include "../../x11/gtk2/modules.mk"

REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		/bin/bash
REPLACE.sh.new=		${SH}
REPLACE_FILES.sh=	configure
REPLACE_FILES.sh+=	scripts/gcin-user-setup
REPLACE_FILES.sh+=	scripts/modify-XIM
REPLACE_FILES.sh+=	scripts/utf8-edit

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
