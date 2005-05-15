# $NetBSD: Makefile,v 1.6 2005/05/15 22:02:28 jlam Exp $
#

DISTNAME=		routeplanner_0.11
PKGNAME=		routeplanner-cli-0.11
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=routeplanner/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://routeplanner.sourceforge.net/
COMMENT=		Highway trip planner written in Python

WRKSRC=			${WRKDIR}/routeplanner-0.11
NO_BUILD=		yes
PKGSRC_USE_TOOLS+=	gzip

PYTHON_PATCH_SCRIPTS=	rpcli
RPLIBDIR=		${PREFIX}/lib/routeplanner
RPPY= rpcli.py rpcountry.py rpdbase.py rpunits.py rpcity.py rproute.py
RPDB= Basic-USA.rpl3 NorthAmerica.rpl3

RP_LIBDIR_SED=	"s|/usr/share/routeplanner|${RPLIBDIR}|g"

post-patch:
	for i in rpcli rpcli.py;do \
		${MV} ${WRKSRC}/$$i ${WRKSRC}/$$i.tmp && \
		${SED} ${RP_LIBDIR_SED} <${WRKSRC}/$$i.tmp >${WRKSRC}/$$i; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rpcli ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${RPLIBDIR}
	for i in ${RPPY}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${RPLIBDIR}; \
	done
	for i in ${RPDB}; do \
		${GZIP_CMD} -c ${WRKSRC}/$$i >${RPLIBDIR}/$$i.gz; \
	done

# optional speedup
#.include "../../devel/py-kjbuckets/buildlink3.mk"
#.include "../../devel/py-pqueue/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
