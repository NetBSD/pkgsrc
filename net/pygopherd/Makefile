# $NetBSD: Makefile,v 1.39 2022/01/10 22:18:58 wiz Exp $

DISTNAME=	pygopherd_2.0.16
PKGREVISION=	7
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/devel/gopher/Downloads/pygopherd/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://gopher.quux.org:70/devel/gopher/pygopherd/
COMMENT=	Gopher server
LICENSE=	gnu-gpl-v2

PKG_SYSCONFSUBDIR=	pygopherd
EXAMPLEDIR=		${PREFIX}/share/examples/pygopherd
RUNTIMEDIR=		${VARBASE}/gopher

BUILD_DEFS+=	VARBASE

GOPHER_USER=	gopher
GOPHER_GROUP=	gopher
PKG_GROUPS=	${GOPHER_GROUP}
PKG_USERS=	${GOPHER_USER}:${GOPHER_GROUP}
OWN_DIRS_PERMS=	${RUNTIMEDIR} ${GOPHER_USER} ${GOPHER_GROUP} 0750

CONF_FILES=	${EXAMPLEDIR}/pygopherd.conf ${PKG_SYSCONFDIR}/pygopherd.conf
CONF_FILES+=	${EXAMPLEDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
EGFILES=	${WRKSRC}/examples/gophermap
EGFILES+=	${WRKSRC}/conf/mime.types
EGFILES+=	${WRKSRC}/conf/pygopherd.conf

RCD_SCRIPTS=	pygopherd
FILES_SUBST+=	RUNTIMEDIR=${RUNTIMEDIR:Q}
FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.0.16
REPLACE_PYTHON=			bin/pygopherd
REPLACE_PYTHON+=		pygopherd/GopherExceptionsTest.py
REPLACE_PYTHON+=		pygopherd/fileextTest.py
REPLACE_PYTHON+=		pygopherd/gopherentryTest.py
REPLACE_PYTHON+=		pygopherd/initializationTest.py
REPLACE_PYTHON+=		pygopherd/testutil.py

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	setup.py
SUBST_FILES.man+=	bin/pygopherd
SUBST_FILES.man+=	conf/pygopherd.conf
SUBST_FILES.man+=	doc/pygopherd.8
SUBST_VARS.man=		PKG_SYSCONFDIR EXAMPLEDIR VARBASE
SUBST_VARS.man+=	GOPHER_USER GOPHER_GROUP RUNTIMEDIR

EGG_NAME=	${PKGBASE}-2.0.15

INSTALLATION_DIRS=	share/examples/pygopherd ${PKGMANDIR}/man8

# XXX this is needed for the RCD script
post-extract:
	${MV} ${WRKDIR}/pygopherd ${WRKDIR}/${DISTNAME}

post-install:
	for egfile in ${EGFILES}; do \
		${INSTALL_DATA} $$egfile ${DESTDIR}${EXAMPLEDIR}; \
	done
	${INSTALL_MAN} ${WRKSRC}/doc/pygopherd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
