# $NetBSD: Makefile,v 1.1.1.1 2003/09/30 17:27:29 recht Exp $
#

DISTNAME=	pygopherd_2.0.3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/devel/gopher/Downloads/pygopherd/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gopher.quux.org:70/devel/gopher/pygopherd/
COMMENT=	Gopher server

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PKG_SYSCONFSUBDIR=	pygopherd
EXAMPLEDIR=	${PREFIX}/share/examples/pygopherd
RUNTIMEDIR=	/var/gopher

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
SEDFILES=	${WRKSRC}/setup.py ${WRKSRC}/bin/pygopherd
SEDFILES+=	${WRKSRC}/conf/pygopherd.conf ${WRKSRC}/pygopherd.8

RCD_SCRIPTS=	pygopherd
FILES_SUBST+=	RUNTIMEDIR=${RUNTIMEDIR}
FILES_SUBST+=	PYTHONBIN=${PYTHONBIN}

PYTHON_PATCH_SCRIPTS=	bin/pygopherd
PYTHON_PATCH_SCRIPTS+=	pygopherd/GopherExceptionsTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/fileextTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/gopherentryTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/initializationTest.py
PYTHON_PATCH_SCRIPTS+=	pygopherd/testutil.py

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth

# XXX this is needed for the RCD script
post-extract:
	${MV} ${WRKDIR}/pygopherd ${WRKDIR}/pygopherd_2.0.3

post-patch:
	for sedfile in ${SEDFILES}; do \
		${MV} $$sedfile $$sedfile.sed; \
		${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
			-e "s|%%EXAMPLEDIR%%|${EXAMPLEDIR}|g" \
			$$sedfile.sed > $$sedfile; \
	done
	for pyfile in ${PYSED}; do\
		${MV} $$pyfile $$pyfile.sed; \
		${SED} -e "s|/usr/bin/python2.2|${PYTHONBIN}|g" \
			$$pyfile.sed > $$pyfile; \
	done

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	for egfile in ${EGFILES}; do \
		${INSTALL_DATA} $$egfile ${EXAMPLEDIR}; \
	done
	${INSTALL_MAN} ${WRKSRC}/pygopherd.8 ${PREFIX}/man/man8

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
