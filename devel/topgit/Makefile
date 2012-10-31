# $NetBSD: Makefile,v 1.2 2012/10/31 11:19:51 asau Exp $

DISTNAME=	topgit_0.7.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/topgit/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://repo.or.cz/w/topgit.git
COMMENT=	Different patch queue manager

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_ENV+=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
