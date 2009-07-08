# $NetBSD: Makefile,v 1.26 2009/07/08 15:15:15 joerg Exp $
#

DISTNAME=	dflowers-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://www.shell.linux.se/bm/index.php?page=xmmsplugin
# AWOL
COMMENT=	XMMS plugin for dual flower scope

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib/xmms/Visualization

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
