# $NetBSD: Makefile,v 1.15 2012/04/05 02:58:24 sbd Exp $
#

DISTNAME=	aspell-nb-0.50.1-0
PKGNAME=	${DISTNAME:C/nb-(.*)-(.*)$/norwegian-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/nb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Norwegian language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"
.if ${PKG_FORMAT} == "pkg" && ${OPSYS} == "Linux"
BROKEN=	Can not be packaged on Linux
.endif

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
