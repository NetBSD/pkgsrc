# $NetBSD: Makefile,v 1.2 2007/08/30 19:55:30 joerg Exp $

DISTNAME=	crossfire-1.9.0-1.maps
PKGNAME=	crossfire-maps-1.9.0.1
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crossfire/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	X11 multi/single player game similar to gauntlet and nethack

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	crossfire-server>=1.9.0:../../games/crossfire-server

USE_TOOLS+=	bash:run perl:run

WRKSRC=			${WRKDIR}/maps
NO_BUILD=		yes

PLIST_SRC=	${WRKDIR}/PLIST PLIST

REPLACE_BASH+=	brest/pshops/pshop_copier
REPLACE_PERL+=	Info/combine.pl Info/map_sed.pl Info/rewrite_exits.pl
REPLACE_PERL+=	Info/rewrite_styles.pl Info/update_apart.pl Info/update_exits.pl

do-install:
	cd ${WRKDIR} && ${CP} -R maps ${DESTDIR}${PREFIX}/share/crossfire
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/crossfire/maps -type f -print >> ${WRKDIR}/PLIST

.include "../../mk/bsd.pkg.mk"
