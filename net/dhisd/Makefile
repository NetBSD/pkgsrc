# $NetBSD: Makefile,v 1.5 2003/12/30 17:27:31 cjep Exp $
#

DISTNAME=	dhisd-5.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.dhis.org/
COMMENT=	DynDNS server

DEPENDS+=	gmp>=3.0:../../devel/gmp

do-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dhisd
		${INSTALL_DATA} \
			${WRKSRC}/*db.sample \
			${PREFIX}/share/examples/dhisd
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dhisd
		${INSTALL_DATA} \
			${WRKSRC}/CONTRIBUTORS  \
			${WRKSRC}/COPYRIGHT  \
			${WRKSRC}/INSTALL  \
			${WRKSRC}/MODULES  \
			${WRKSRC}/README  \
			${PREFIX}/share/doc/dhisd
		${INSTALL_PROGRAM} \
			${WRKSRC}/dhisd \
			${PREFIX}/bin
		${INSTALL_PROGRAM} \
			${WRKSRC}/genkeys \
			${PREFIX}/bin/dhisd-genkeys
		${CHOWN} ${ROOT_USER} \
			${PREFIX}/bin/dhisd-genkeys \
			${PREFIX}/bin/dhisd
		${CHMOD} 700 \
			${PREFIX}/bin/dhisd-genkeys \
			${PREFIX}/bin/dhisd

.include "../../mk/bsd.pkg.mk"
