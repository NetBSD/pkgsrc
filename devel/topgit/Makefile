# $NetBSD: Makefile,v 1.1.1.1 2009/03/08 05:58:07 minskim Exp $

DISTNAME=	topgit_0.7.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/topgit/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://repo.or.cz/w/topgit.git
COMMENT=	Different patch queue manager

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_ENV+=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
