# $NetBSD: Makefile,v 1.1.1.1 2003/12/27 22:45:37 salo Exp $
#

DISTNAME=		blccc-1.99
CATEGORIES=		misc
MASTER_SITES=		http://sven.gimp.org/blinkenlights/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights Chaos Control Center

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

EGDIR=			${PREFIX}/share/examples/blccc

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

.include "../../devel/blib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
