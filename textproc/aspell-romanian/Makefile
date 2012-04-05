# $NetBSD: Makefile,v 1.16 2012/04/05 02:58:24 sbd Exp $
#

DISTNAME=	aspell-ro-0.50-2
PKGNAME=	${DISTNAME:C/ro-(.*)-(.*)$/romanian-\1.\2/}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ro/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Romanian language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"
.if ${PKG_FORMAT} == "pkg" && ${OPSYS} == "Linux"
BROKEN=	Can not be packaged on Linux
.endif

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
