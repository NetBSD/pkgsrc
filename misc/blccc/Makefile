# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:22 wiz Exp $
#

DISTNAME=		blccc-1.99
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		http://sven.gimp.org/blinkenlights/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights Chaos Control Center

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
SHLIBTOOL_OVERRIDE=	libtool

EGDIR=			${PREFIX}/share/examples/blccc

.include "../../devel/blib/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/movies
	${INSTALL_DATA_DIR} ${EGDIR}/on-demand
	for f in config.xml loveletters.xml playlist.default.xml	\
		movies/bushfire-test.gif movies/bushfire_60frames.gif	\
		movies/camel.blm movies/the_fly.blm on-demand/4467.blm;	\
	do								\
		${INSTALL_DATA} ${WRKSRC}/examples/$${f} ${EGDIR}/$${f};\
	done

.include "../../mk/bsd.pkg.mk"
