# $NetBSD: Makefile,v 1.6 2002/06/13 08:18:36 martti Exp $
#

DISTNAME=	ekg-20020610
PKGNAME=	ekg-0.20020610
CATEGORIES=	chat
MASTER_SITES=	http://people.arhea.net/dawszy/NetBSD/ekg/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Experimental Gadu-Gadu Client (Polish instant messaging system)

USE_GNU_READLINE=	YES
HAS_CONFIGURE=		YES
USE_GMAKE=		YES

CONFIGURE_ARGS+=	--with-readline=${PREFIX}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--without-debug

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
