# $NetBSD: Makefile,v 1.18 2014/05/09 07:37:13 wiz Exp $
#

DISTNAME=		routeplanner_0.11
PKGNAME=		routeplanner-cli-0.11
PKGREVISION=		4
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=routeplanner/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://routeplanner.sourceforge.net/
COMMENT=		Highway trip planner written in Python

WRKSRC=			${WRKDIR}/routeplanner-0.11
NO_BUILD=		yes
USE_TOOLS+=		gzip

REPLACE_PYTHON=	rpcli
RPLIBDIR=		${PREFIX}/lib/routeplanner
RPPY= rpcli.py rpcountry.py rpdbase.py rpunits.py rpcity.py rproute.py
RPDB= Basic-USA.rpl3 NorthAmerica.rpl3

RP_LIBDIR_SED=	"s|/usr/share/routeplanner|${RPLIBDIR}|g"

INSTALLATION_DIRS=	bin

post-patch:
	for i in rpcli rpcli.py;do \
		${MV} ${WRKSRC}/$$i ${WRKSRC}/$$i.tmp && \
		${SED} ${RP_LIBDIR_SED} <${WRKSRC}/$$i.tmp >${WRKSRC}/$$i; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rpcli ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${RPLIBDIR}
	for i in ${RPPY}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${RPLIBDIR}; \
	done
	for i in ${RPDB}; do \
		${GZIP_CMD} -c ${WRKSRC}/$$i >${DESTDIR}${RPLIBDIR}/$$i.gz; \
	done

# optional speedup
#PYTHON_VERSIONS_INCOMPATIBLE= 33 34 # py-kjbuckets
#.include "../../devel/py-kjbuckets/buildlink3.mk"
#.include "../../devel/py-pqueue/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
