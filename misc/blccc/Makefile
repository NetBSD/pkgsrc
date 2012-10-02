# $NetBSD: Makefile,v 1.26 2012/10/02 17:11:33 tron Exp $
#

DISTNAME=		blccc-1.99
PKGREVISION=		17
CATEGORIES=		misc
MASTER_SITES=		http://sven.gimp.org/blinkenlights/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights Chaos Control Center

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
SHLIBTOOL_OVERRIDE=	# empty

EGDIR=			${PREFIX}/share/examples/blccc

INSTALLATION_DIRS=	${EGDIR}/movies ${EGDIR}/on-demand

.include "../../devel/blib/buildlink3.mk"

post-install:
	for f in config.xml loveletters.xml playlist.default.xml	\
		movies/bushfire-test.gif movies/bushfire_60frames.gif	\
		movies/camel.blm movies/the_fly.blm on-demand/4467.blm;	\
	do								\
		${INSTALL_DATA} ${WRKSRC}/examples/$${f} ${DESTDIR}${EGDIR}/$${f};\
	done

.include "../../mk/bsd.pkg.mk"
