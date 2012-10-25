# $NetBSD: Makefile,v 1.18 2012/10/25 06:55:40 asau Exp $
#

DISTNAME=	aspell6-en-6.0-0
PKGNAME=	aspell-english-6.0.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/en/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	English language support for aspell

HAS_CONFIGURE=	YES
CONFIGURE_ENV+=	ASPELL=${BUILDLINK_PREFIX.aspell}/bin/aspell
CONFIGURE_ENV+=	PREZIP=${BUILDLINK_PREFIX.aspell}/bin/prezip-bin

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
