# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:54 jschauma Exp $
#

DISTNAME=	mrt-2.2.2a-Aug11
PKGNAME=	mrt-2.2.2a.20000811
WRKSRC=		${WRKDIR}/mrt/src
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/net-research/mrt/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.mrtd.net/
COMMENT=	Multi-threaded Routing Toolkit

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
