# $NetBSD: Makefile,v 1.5 2002/05/05 22:24:15 hubertf Exp $
#

DISTNAME=	ekg-20020503
PKGNAME=	ekg-0.20020503
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
