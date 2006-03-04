# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:45 jlam Exp $
#

DISTNAME=	aspell6-uk-1.1-0
PKGNAME=	${DISTNAME:C/6-uk-(.*)-(.*)$/-ukrainian-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/uk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Ukrainian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
