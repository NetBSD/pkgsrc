# $NetBSD: Makefile,v 1.43 2013/10/10 14:42:24 ryoon Exp $
#

DISTNAME=		kanjipad-2.0.0
PKGREVISION=	25
CATEGORIES=		misc
MASTER_SITES=		http://fishsoup.net/software/kanjipad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fishsoup.net/software/kanjipad/
COMMENT=		Japanese handwriting recognition

USE_TOOLS+=		gmake perl pkg-config
LDFLAGS+=		-lm	# direct link required by ld v2.22

INSTALLATION_DIRS+=	share/doc/kanjipad

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/kanjipad

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
