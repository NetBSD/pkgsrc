# $NetBSD: Makefile,v 1.41 2012/12/16 01:52:35 obache Exp $
#

DISTNAME=		xen-2.0.7-src
PKGNAME=		xentools20-2.0.7
PKGREVISION=		16
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cl.cam.ac.uk/research/srg/netos/xen/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.cl.cam.ac.uk/research/srg/netos/xen/
COMMENT=		Userland Tools for Xen

LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PKG_SYSCONFSUBDIR=	xen

ONLY_FOR_PLATFORM=	Linux-2.[46]*-i386 NetBSD-*-i386

CONFLICTS+=		libxen-[0-9]*

WRKSRC=			${WRKDIR}/xen-2.0/tools

EGDIR=			${PREFIX}/share/examples/xen
MESSAGE_SUBST=		EGDIR=${EGDIR}

USE_TOOLS+=		gmake
MAKE_ENV+=		EGDIR=${EGDIR:Q}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}

PY_PATCHPLIST=		yes
PYTHON_PATCH_SCRIPTS=	python/xen/util/console_client.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/server/SrvServer.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/XendClient.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/sxp.py
PYTHON_PATCH_SCRIPTS+=	xfrd/xfrdClient.py
PYTHON_PATCH_SCRIPTS+=	misc/xensymoops
PYTHON_PATCH_SCRIPTS+=	misc/xencons
PYTHON_PATCH_SCRIPTS+=	misc/xm
PYTHON_PATCH_SCRIPTS+=	misc/xensv
PYTHON_PATCH_SCRIPTS+=	misc/netfix
PYTHON_PATCH_SCRIPTS+=	misc/xend
PYTHON_PATCH_SCRIPTS+=	xentrace/xentrace_format

SUBST_CLASSES+=          paths py conf
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	python/xen/xend/server/SrvDaemon.py
SUBST_FILES.paths+=	python/xen/xend/XendDomainInfo.py
SUBST_FILES.paths+=	python/xen/sv/Daemon.py
SUBST_SED.paths=	-e "s|/usr/sbin|${PREFIX}/sbin|g"
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

SUBST_STAGE.py=		pre-configure
SUBST_FILES.py=		python/Makefile
SUBST_SED.py=		-e "s,python,${PYTHONBIN},g"

SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	python/xen/xend/XendRoot.py
SUBST_SED.conf=		-e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		proc
SUBST_STAGE.proc=	pre-configure
SUBST_FILES.proc=	python/xen/xend/XendVnet.py
SUBST_FILES.proc+=	libxc/xc_misc.c
SUBST_FILES.proc+=	xentrace/xentrace.c
SUBST_SED.proc=		-e "s|/proc|/kern|g"
PROCPATH=		/kern
.else
PROCPATH=		/proc
.endif

RCD_SCRIPTS=		xend xendomains
FILES_SUBST+=		RCD_INTERPRETER=${PYTHONBIN:Q}
FILES_SUBST+=		PROCPATH=${PROCPATH:Q}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

XEND_SCRIPTS=		network block-enbd vif-bridge block-file

CONF_FILES=		${EGDIR}/xend-config.sxp \
			${PKG_SYSCONFDIR}/xend-config.sxp
.for s in ${XEND_SCRIPTS}
CONF_FILES_PERMS+=	${EGDIR}/${s} ${PKG_SYSCONFDIR}/${s}		\
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor

pre-build:
	${MKDIR} ${WRKSRC}/libxc/xen/NetBSD
	${CP} ${FILESDIR}/xenio.h ${WRKSRC}/libxc/xen/NetBSD

.if ${OPSYS} == "NetBSD"
post-build:
	cd ${FILESDIR}; for src in *-nbsd; do				\
		dst="$${src%-nbsd}";					\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			$$src > ${WRKSRC}/examples/$$dst;		\
	done
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	for f in xend-config.sxp xmexample1 xmexample2 xmexample3; do	\
		${INSTALL_DATA} ${WRKSRC}/examples/$$f ${DESTDIR}${EGDIR}/$$f;	\
	done
.for s in ${XEND_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${s} ${DESTDIR}${EGDIR}/${s}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
