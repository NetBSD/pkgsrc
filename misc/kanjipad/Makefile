# $NetBSD: Makefile,v 1.57 2018/11/14 22:22:03 kleink Exp $

DISTNAME=		kanjipad-2.0.0
PKGREVISION=		38
CATEGORIES=		misc
MASTER_SITES=		https://fishsoup.net/software/kanjipad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fishsoup.net/software/kanjipad/
COMMENT=		Japanese handwriting recognition

USE_TOOLS+=		gmake perl pkg-config
LDFLAGS+=		-lm	# direct link required by ld v2.22

INSTALLATION_DIRS+=	share/doc/kanjipad

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/kanjipad

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
