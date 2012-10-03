# $NetBSD: Makefile,v 1.20 2012/10/03 00:02:46 asau Exp $
#

DISTNAME=	xaric-0.12.1
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	http://rexfeany.com/software/xaric/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rexfeany.com/software/xaric/
COMMENT=	IRC client similar to BitchX and ircII

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--enable-optimize

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
