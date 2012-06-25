# $NetBSD: Makefile,v 1.20 2012/06/25 11:27:08 joerg Exp $
#

DISTNAME=	mined-2000.15
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	Html-aware editor

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FILE=	makefile
USE_TOOLS+=	gmake

post-install:
		${CHMOD} -x ${DESTDIR}${PREFIX}/share/mined/conf_user/xinitrc.mined

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-invalid-source-encoding
.endif

MAKE_FLAGS+=	OPT=${CFLAGS:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
