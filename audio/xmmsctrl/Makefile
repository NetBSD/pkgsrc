# $NetBSD: Makefile,v 1.12 2008/03/02 06:10:34 jlam Exp $
#

DISTNAME=		xmmsctrl-1.6
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://user.it.uu.se/~adavid/utils/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://user.it.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

.include "../../audio/xmms/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
