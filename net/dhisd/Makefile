# $NetBSD: Makefile,v 1.12 2005/06/17 03:50:24 jlam Exp $
#

DISTNAME=	dhisd-5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dhis.org/
COMMENT=	DynDNS server

INSTALLATION_DIRS=	bin

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
