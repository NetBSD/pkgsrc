# $NetBSD: Makefile,v 1.13 2009/06/14 22:58:07 joerg Exp $
#

DISTNAME=	mrt-2.2.2a-Aug11
PKGNAME=	mrt-2.2.2a.20000811
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/net-research/mrt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mrtd.net/
COMMENT=	Multi-threaded Routing Toolkit

WRKSRC=		${WRKDIR}/mrt/src
GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKSRC}/.PLIST_SRC

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/examples/mrt

# nuke yet-to-be-ready directories, configure.in is written in a strange way
post-extract:
	(cd ${WRKSRC}/programs; ${RM} -fr route_tracker sospf srip)

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${INSTALL_DATA} ${WRKSRC}/programs/*/*.conf \
		${DESTDIR}${PREFIX}/share/examples/mrt
	(cd ${DESTDIR}${PREFIX}; ${FIND} share/examples/mrt -type f -print \
		>> ${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
