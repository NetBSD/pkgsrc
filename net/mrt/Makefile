# $NetBSD: Makefile,v 1.15 2011/03/21 04:53:49 obache Exp $
#

DISTNAME=	mrt-2.2.2a-Aug11
PKGNAME=	mrt-2.2.2a.20000811
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/net-research/mrt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mrtd.net/
COMMENT=	Multi-threaded Routing Toolkit

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/mrt/src
GNU_CONFIGURE=	yes
DESTDIR_VARNAME=	# empty
INSTALL_MAKE_FLAGS+=	DESTDIR=${DESTDIR}${PREFIX}/sbin
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

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
