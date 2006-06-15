# $NetBSD: Makefile,v 1.14 2006/06/15 13:43:33 wiz Exp $
#

DISTNAME=	aspell6-en-6.0-0
PKGNAME=	aspell-english-6.0.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/en/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	English language support for aspell

HAS_CONFIGURE=	YES
CONFIGURE_ENV+=	ASPELL=${BUILDLINK_PREFIX.aspell}/bin/aspell
CONFIGURE_ENV+=	PREZIP=${BUILDLINK_PREFIX.aspell}/bin/prezip-bin

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
