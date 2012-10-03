# $NetBSD: Makefile,v 1.32.2.1 2012/10/03 12:08:43 spz Exp $
#

DISTNAME=		kanjipad-2.0.0
PKGREVISION=	16
CATEGORIES=		misc
MASTER_SITES=		http://fishsoup.net/software/kanjipad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fishsoup.net/software/kanjipad/
COMMENT=		Japanese handwriting recognition

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pkg-config
LDFLAGS+=		-lm	# direct link required by ld v2.22

INSTALLATION_DIRS+=	share/doc/kanjipad

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/kanjipad

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
