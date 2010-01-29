# $NetBSD: Makefile,v 1.16 2010/01/29 16:08:17 joerg Exp $
#

DISTNAME=	xaric-0.12.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://rexfeany.com/software/xaric/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rf.cx/software/xaric/
COMMENT=	IRC client similar to BitchX and ircII

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--enable-optimize

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
