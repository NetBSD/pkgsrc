# $NetBSD: Makefile,v 1.18 2011/03/30 21:56:32 joerg Exp $
#

DISTNAME=	xaric-0.12.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://rexfeany.com/software/xaric/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rexfeany.com/software/xaric/
COMMENT=	IRC client similar to BitchX and ircII

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--enable-optimize

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
