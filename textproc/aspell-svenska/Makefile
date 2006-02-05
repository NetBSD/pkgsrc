# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:00 joerg Exp $
#

DISTNAME=	aspell-sv-0.51-0
PKGNAME=	${DISTNAME:C/sv-(.*)-(.*)$/svenska-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sv/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Swedish language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
