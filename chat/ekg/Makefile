# $NetBSD: Makefile,v 1.1.1.1 2002/03/18 06:42:34 zuntum Exp $
#

DISTNAME=	ekg-20020317
PKGNAME=	ekg-0.20020317
CATEGORIES=	chat
MASTER_SITES=	http://dev.null.pl/ekg/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Experimental Gadu-Gadu Client

HAS_CONFIGURE=		YES
USE_GNU_READLINE=	YES
USE_GMAKE=		YES

CONFIGURE_ARGS+=	--with-readline=${PREFIX}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

REPLACE_PERL=		docs/ekl.pl

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
