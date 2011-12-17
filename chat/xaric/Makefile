# $NetBSD: Makefile,v 1.19 2011/12/17 10:14:52 sbd Exp $
#

DISTNAME=	xaric-0.12.1
PKGREVISION=	3
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

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
