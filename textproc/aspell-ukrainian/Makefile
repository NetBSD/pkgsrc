# $NetBSD: Makefile,v 1.15 2009/12/02 18:10:33 snj Exp $

DISTNAME=	aspell6-uk-1.4.0-0
PKGNAME=	${DISTNAME:C/6-uk-(.*)-(.*)$/-ukrainian-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/uk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Ukrainian language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
