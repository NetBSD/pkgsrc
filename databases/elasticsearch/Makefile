# $NetBSD: Makefile,v 1.8 2015/01/21 15:42:50 fhajny Exp $

DISTNAME=	elasticsearch-1.4.2
CATEGORIES=	textproc
MASTER_SITES=	https://download.elasticsearch.org/elasticsearch/elasticsearch/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.elasticsearch.org/
COMMENT=	Distributed RESTful Search Engine
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	yes
NO_BUILD=	yes

PKG_SYSCONFSUBDIR=	elasticsearch
EXDIR=			${PREFIX}/share/examples/elasticsearch
EGDIR=			${PREFIX}/share/elasticsearch

CONFS=	elasticsearch.yml logging.yml
.for f in ${CONFS}
CONF_FILES+=	${EXDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
DOCS=		LICENSE.txt NOTICE.txt README.textile
BINS=		elasticsearch elasticsearch.in.sh plugin

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-*-i386)
SIGAR_PLATFORM=	universal-macosx
.elif !empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
SIGAR_PLATFORM=	universal64-macosx
.elif !empty(MACHINE_PLATFORM:MFreeBSD-5*-i386)
SIGAR_PLATFORM=	x86-freebsd-5
.elif !empty(MACHINE_PLATFORM:MFreeBSD-6*-i386)
SIGAR_PLATFORM=	x86-freebsd-6
.elif !empty(MACHINE_PLATFORM:MFreeBSD-6*-x86_64)
SIGAR_PLATFORM=	amd64-freebsd-6
.elif !empty(MACHINE_PLATFORM:MLinux-*-i386)
SIGAR_PLATFORM=	x86-linux
.elif !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
SIGAR_PLATFORM=	amd64-linux
.elif !empty(MACHINE_PLATFORM:MSunOS-*-i386)
SIGAR_PLATFORM=	x86-solaris
.elif !empty(MACHINE_PLATFORM:MSunOS-*-sparc)
SIGAR_PLATFORM=	sparc-solaris
.elif !empty(MACHINE_PLATFORM:MSunOS-*-sparc64)
SIGAR_PLATFORM=	sparc64-solaris
.elif !empty(MACHINE_PLATFORM:MSunOS-*-x86_64)
SIGAR_PLATFORM=	amd64-solaris
.endif

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SHLIB_EXT=	dylib
.else
SHLIB_EXT=	so
.endif

BUILD_DEFS+=	ES_USER ES_GROUP ES_DBDIR ES_LOGDIR ES_PIDDIR ES_TMPDIR

ES_USER?=	elasticsearch
ES_GROUP?=	${ES_USER}
ES_LIBDIR?=	${PREFIX}/lib/elasticsearch
ES_DBDIR?=	${VARBASE}/db/elasticsearch
ES_LOGDIR?=	${VARBASE}/log/elasticsearch
ES_PIDDIR?=	${VARBASE}/run
ES_TMPDIR?=	${VARBASE}/tmp/elasticsearch

PKG_USERS_VARS+=	ES_USER
PKG_GROUPS_VARS+=	ES_GROUP
PKG_GROUPS=		${ES_GROUP}
PKG_USERS=		${ES_USER}:${ES_GROUP}

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME} ES_USER=${ES_USER}	\
			ES_GROUP=${ES_GROUP} ES_LIBDIR=${ES_LIBDIR}	\
			ES_LOGDIR=${ES_LOGDIR} ES_PIDDIR=${ES_PIDDIR}	\
			ES_DBDIR=${ES_DBDIR} ES_TMPDIR=${ES_TMPDIR}	\
			DISTNAME=${DISTNAME}

RCD_SCRIPTS=		elasticsearch

OWN_DIRS_PERMS+=	${ES_LOGDIR} ${ES_USER} ${ES_GROUP} 0700
OWN_DIRS_PERMS+=	${ES_DBDIR} ${ES_USER} ${ES_GROUP} 0700
OWN_DIRS_PERMS+=	${ES_TMPDIR} ${ES_USER} ${ES_GROUP} 0700
INSTALLATION_DIRS+=	${EXDIR} ${ES_LIBDIR} ${PREFIX}/share/doc/elasticsearch
INSTALLATION_DIRS+=	${ES_LIBDIR}/plugins ${EGDIR}

PLIST_VARS+=		sigar
.if !empty(SIGAR_PLATFORM)
PLIST.sigar=		yes
PLIST_SUBST+=		SIGAR_FILE=libsigar-${SIGAR_PLATFORM}.${SHLIB_EXT}
PRINT_PLIST_AWK+=	{gsub(/libsigar-$(SIGAR_PLATFORM).$(SHLIB_EXT)/,"$${SIGAR_FILE}", $$0);}
INSTALLATION_DIRS+=	${ES_LIBDIR}/sigar
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	config/elasticsearch.yml
SUBST_VARS.paths=	PKG_SYSCONFDIR ES_DBDIR ES_LIBDIR ES_LOGDIR ES_TMPDIR

do-install:
.for f in ${CONFS}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${DESTDIR}${EXDIR}
.endfor
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}	\
		${DESTDIR}${PREFIX}/share/doc/elasticsearch
.endfor
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f}	\
		${DESTDIR}${PREFIX}/share/elasticsearch
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${ES_LIBDIR}
.if !empty(SIGAR_PLATFORM)
	${INSTALL_DATA} ${WRKSRC}/lib/sigar/sigar-*.jar ${DESTDIR}${ES_LIBDIR}/sigar/
	${INSTALL_LIB} ${WRKSRC}/lib/sigar/libsigar-${SIGAR_PLATFORM}.${SHLIB_EXT} ${DESTDIR}${ES_LIBDIR}/sigar/
.endif

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
