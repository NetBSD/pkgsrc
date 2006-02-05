# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:00 joerg Exp $

DISTNAME=	aspell5-ga-3.5-0
PKGNAME=	aspell-gaeilge-3.5.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=   ${MASTER_SITE_GNU:=aspell/dict/ga/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
