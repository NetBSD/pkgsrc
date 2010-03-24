# $NetBSD: Makefile,v 1.15 2010/03/24 19:43:28 asau Exp $
#

DISTNAME=	dhisd-5.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dhis.org/
COMMENT=	DynDNS server

INSTALLATION_DIRS=	bin share/examples/dhisd share/doc/dhisd
PKG_DESTDIR_SUPPORT=	destdir

do-install:
		${INSTALL_DATA} \
			${WRKSRC}/*db.sample \
			${DESTDIR}${PREFIX}/share/examples/dhisd
		${INSTALL_DATA} \
			${WRKSRC}/CONTRIBUTORS  \
			${WRKSRC}/COPYRIGHT  \
			${WRKSRC}/INSTALL  \
			${WRKSRC}/MODULES  \
			${WRKSRC}/README  \
			${DESTDIR}${PREFIX}/share/doc/dhisd
		${INSTALL_PROGRAM} \
			${WRKSRC}/dhisd \
			${DESTDIR}${PREFIX}/bin
		${INSTALL_PROGRAM} \
			${WRKSRC}/genkeys \
			${DESTDIR}${PREFIX}/bin/dhisd-genkeys
		${CHOWN} ${ROOT_USER} \
			${DESTDIR}${PREFIX}/bin/dhisd-genkeys \
			${DESTDIR}${PREFIX}/bin/dhisd
		${CHMOD} 700 \
			${DESTDIR}${PREFIX}/bin/dhisd-genkeys \
			${DESTDIR}${PREFIX}/bin/dhisd

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
