# $NetBSD: Makefile,v 1.7 2004/01/20 12:22:20 agc Exp $
#

DISTNAME=	mrt-2.2.2a-Aug11
PKGNAME=	mrt-2.2.2a.20000811
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/net-research/mrt/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mrtd.net/
COMMENT=	Multi-threaded Routing Toolkit

WRKSRC=		${WRKDIR}/mrt/src
GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKSRC}/.PLIST_SRC

# nuke yet-to-be-ready directories, configure.in is written in a strange way
post-extract:
	(cd ${WRKSRC}/programs; ${RM} -fr route_tracker sospf srip)

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mrt
	${INSTALL_DATA} ${WRKSRC}/programs/*/*.conf \
		${PREFIX}/share/examples/mrt
	(cd ${PREFIX}; ${FIND} share/examples/mrt -type f -print \
		>> ${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d share/examples/mrt -type d -print | \
		${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
