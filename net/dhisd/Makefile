# $NetBSD: Makefile,v 1.8 2004/10/03 00:17:50 tv Exp $
#

DISTNAME=	dhisd-5.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.dhis.org/
COMMENT=	DynDNS server

USE_BUILDLINK3=	yes

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

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
