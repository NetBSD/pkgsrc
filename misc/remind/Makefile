# $NetBSD: Makefile,v 1.5 2000/03/02 00:02:49 kim Exp $

DISTNAME=	remind-03.00.20
PKGNAME=	${DISTNAME:C/0([0-9])/\1/g}
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.doe.carleton.ca/pub/remind-3.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/remind
	(cd ${WRKSRC}; \
		${INSTALL_DATA} -p examples/defs.rem \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} -p scripts/remind-all.csh \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} -p scripts/remind-all.sh \
			${PREFIX}/share/examples/remind)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/remind
	(cd ${WRKSRC}; \
		${INSTALL_DATA} -p docs/README.UNIX \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} -p docs/WHATSNEW.30 \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} -p COPYRIGHT \
			${PREFIX}/share/doc/remind)

.include "../../mk/bsd.pkg.mk"
