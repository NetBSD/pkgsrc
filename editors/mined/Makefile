# $NetBSD: Makefile,v 1.23 2013/10/16 22:37:14 roy Exp $
#

DISTNAME=	mined-2000.15
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	Html-aware editor

MAKE_FILE=	makefile
USE_TOOLS+=	gmake

post-install:
		${CHMOD} -x ${DESTDIR}${PREFIX}/share/mined/conf_user/xinitrc.mined

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-invalid-source-encoding
.endif

MAKE_FLAGS+=	OPT=${CFLAGS:Q}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
