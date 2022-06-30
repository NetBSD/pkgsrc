# $NetBSD: Makefile,v 1.25 2022/06/30 11:18:45 nia Exp $

DISTNAME=	bg5ps-1.3.0
PKGREVISION=	9
CATEGORIES=	print converters
MASTER_SITES=	# ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/
COMMENT=	Convert Big5/GB encoded files to postscript

DEPENDS+=	arphic-ttf>=2.11:../../fonts/arphic-ttf

PKG_SYSCONFSUBDIR?=	bg5ps

REPLACE_PYTHON+=	bg5ps

SUBST_CLASSES+=		config
SUBST_MESSAGE.config=	Fixing configuration files path.
SUBST_STAGE.config=	post-configure
SUBST_FILES.config=	bg5ps
SUBST_VARS.config=	PKG_SYSCONFDIR

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
