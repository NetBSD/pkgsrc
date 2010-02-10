# $NetBSD: Makefile,v 1.19 2010/02/10 19:17:43 joerg Exp $
#

DISTNAME=	pygopherd_2.0.16
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/devel/gopher/Downloads/pygopherd/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://gopher.quux.org:70/devel/gopher/pygopherd/
COMMENT=	Gopher server

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

PKG_SYSCONFSUBDIR=	pygopherd
EXAMPLEDIR=	${PREFIX}/share/examples/pygopherd
RUNTIMEDIR=	${VARBASE}/gopher

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

PYTHON_PATCH_SCRIPTS=	bin/pygopherd
PYTHON_PATCH_SCRIPTS+=	pygopherd/GopherExceptionsTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/fileextTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/gopherentryTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/initializationTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/testutil.py

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	setup.py
SUBST_FILES.man+=	bin/pygopherd
SUBST_FILES.man+=	conf/pygopherd.conf
SUBST_FILES.man+=	doc/pygopherd.8
SUBST_SED.man=		-e 's,%%PREFIX%%,${PREFIX},g'
SUBST_SED.man+=		-e 's,%%EXAMPLEDIR%%,${EXAMPLEDIR},g'

INSTALLATION_DIRS=	share/examples/pygopherd ${PKGMANDIR}/man8

# XXX this is needed for the RCD script
post-extract:
	${MV} ${WRKDIR}/pygopherd ${WRKDIR}/${DISTNAME}

post-install:
	for egfile in ${EGFILES}; do \
		${INSTALL_DATA} $$egfile ${DESTDIR}${EXAMPLEDIR}; \
	done
	${INSTALL_MAN} ${WRKSRC}/doc/pygopherd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
