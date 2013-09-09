# $NetBSD: Makefile,v 1.3 2013/09/09 14:07:59 wiz Exp $

DISTNAME=	topgit_0.7.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/topgit/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://repo.or.cz/w/topgit.git
COMMENT=	Different patch queue manager

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_ENV+=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
