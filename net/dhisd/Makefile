# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:18 jlam Exp $
#

DISTNAME=	dhisd-5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
