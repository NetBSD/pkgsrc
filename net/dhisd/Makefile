# $NetBSD: Makefile,v 1.2 2001/12/05 15:00:47 agc Exp $
#

DISTNAME=	dhisd-5.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.dhis.org
COMMENT=	DynDNS server

DEPENDS+=	gmp-3.*:../../devel/gmp

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
