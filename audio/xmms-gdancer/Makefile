# $NetBSD: Makefile,v 1.19 2008/07/14 12:55:58 joerg Exp $
#

DISTNAME=	gdancer-0.4.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://figz.com/gdancer/files/old/ \
		http://figz.com/gdancer/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://figz.com/gdancer/
COMMENT=	XMMS plugin to animate characters to the beat of the music

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
