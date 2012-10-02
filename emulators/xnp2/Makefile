# $NetBSD: Makefile,v 1.5 2012/10/02 17:11:00 tron Exp $

SNAPSHOTDATE=		20120618
DISTNAME=		xnp2-${SNAPSHOTDATE}
PKGNAME=		xnp2-0.83pl${SNAPSHOTDATE}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://www.asahi-net.or.jp/~aw9k-nnk/np2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://www.asahi-net.or.jp/~aw9k-nnk/np2/
COMMENT=		Neko Project II PC-9801 emulator
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
CONFIGURE_DIRS=		x11

GNU_CONFIGURE=		yes

.include "options.mk"

INSTALLATION_DIRS+=	share/doc/xnp2 ${PKGMANDIR}/ja/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/x11/README.ja \
		${DESTDIR}${PREFIX}/share/doc/xnp2
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnp2.1j	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja/man1/xnp2.1

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
