# $NetBSD: Makefile,v 1.8 2002/09/25 18:05:17 wiz Exp $
#

DISTNAME=	ekg-20020918
PKGNAME=	ekg-0.20020918
CATEGORIES=	chat
MASTER_SITES=	http://people.arhea.net/dawszy/NetBSD/ekg/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Experimental Gadu-Gadu Client (Polish instant messaging system)

USE_GNU_READLINE=	YES
USE_NCURSES=		YES # Package insist on it (patch it out?)
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--without-debug
CONFIGURE_ARGS+=	--enable-ui-ncurses

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
