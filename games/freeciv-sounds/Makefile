# $NetBSD: Makefile,v 1.10 2007/12/29 09:54:58 wiz Exp $

DISTNAME=	stdsounds3
PKGNAME=	freeciv-sounds-3.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/freeciv/contrib/audio/soundsets/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	Freeciv sound sets

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	freeciv-share-[0-9]*:../../games/freeciv-share

WRKSRC=			${WRKDIR}/data
NO_BUILD=		yes

INSTALLATION_DIRS=	share/freeciv

do-install:
	${INSTALL_DATA} ${WRKSRC}/stdsounds.soundspec ${DESTDIR}${PREFIX}/share/freeciv/
	cd ${WRKSRC} && ${PAX} -rw stdsounds ${DESTDIR}${PREFIX}/share/freeciv/

.include "../../mk/bsd.pkg.mk"
