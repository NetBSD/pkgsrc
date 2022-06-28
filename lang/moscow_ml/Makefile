# $NetBSD: Makefile,v 1.43 2022/06/28 11:34:14 wiz Exp $

DISTNAME=	mos201src
PKGNAME=	moscow_ml-2.01
PKGREVISION=	11
CATEGORIES=	lang
MASTER_SITES=	http://www.itu.dk/people/sestoft/mosml/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.dina.kvl.dk/~sestoft/mosml.html
COMMENT=	Moscow ML, a version of Standard ML

WRKSRC=		${WRKDIR}/mosml/src
USE_TOOLS+=	perl pax

BUILD_TARGET=	clean world
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS+=	share/examples/moscow_ml/calc
INSTALLATION_DIRS+=	share/examples/moscow_ml/cgi
INSTALLATION_DIRS+=	share/examples/moscow_ml/lexyacc
INSTALLATION_DIRS+=	share/examples/moscow_ml/lexyacc/cl
INSTALLATION_DIRS+=	share/examples/moscow_ml/manual
INSTALLATION_DIRS+=	share/examples/moscow_ml/mls
INSTALLATION_DIRS+=	share/examples/moscow_ml/modules
INSTALLATION_DIRS+=	share/examples/moscow_ml/parsercomb
INSTALLATION_DIRS+=	share/examples/moscow_ml/paulson
INSTALLATION_DIRS+=	share/examples/moscow_ml/pretty
INSTALLATION_DIRS+=	share/examples/moscow_ml/small
INSTALLATION_DIRS+=	share/examples/moscow_ml/units
INSTALLATION_DIRS+=	share/examples/moscow_ml/weak
INSTALLATION_DIRS+=	share/examples/moscow_ml/webserver

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

post-extract:
	${CHMOD} -x ${WRKDIR}/mosml/examples/modules/matrix.sml

post-install:
	cd ${WRKDIR}/mosml/examples && ${PAX} -rw . \
		${DESTDIR}${PREFIX}/share/examples/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/share/examples/moscow_ml
	${CHMOD} -R ugo+rX ${DESTDIR}${PREFIX}/share/examples/moscow_ml

.include "../../mk/bsd.pkg.mk"
