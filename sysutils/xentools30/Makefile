# $NetBSD: Makefile,v 1.1.1.1 2006/07/02 16:49:31 bouyer Exp $
#

DISTNAME=		xen-3.0.2-2-src
PKGNAME=		xentools30-3.0.2.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.cl.cam.ac.uk/Research/SRG/netos/xen/
COMMENT=		Userland Tools for Xen

#DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PKG_SYSCONFSUBDIR=	xen

ONLY_FOR_PLATFORM=	Linux-2.[46]*-i386 NetBSD-*-i386

CONFLICTS+=		libxen-[0-9]*
CONFLICTS+=		xentools20-[0-9]*

WRKSRC=			${WRKDIR}/xen-3.0.2-2/tools

EGDIR=			${PREFIX}/share/examples/xen
MESSAGE_SUBST=		EGDIR=${EGDIR}

USE_TOOLS+=		gmake
MAKE_ENV+=		EGDIR=${EGDIR:Q}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}
MAKE_ENV+=		XEN_TARGET_ARCH="x86_32"
MAKE_ENV+=		XEN_NO_IOEMU=yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22
PY_PATCHPLIST=		yes
PYTHON_PATCH_SCRIPTS=	ioemu/keymaps/convert-map
PYTHON_PATCH_SCRIPTS+=	misc/xm
PYTHON_PATCH_SCRIPTS+=	misc/netfix
PYTHON_PATCH_SCRIPTS+=	misc/xen-bugtool
PYTHON_PATCH_SCRIPTS+=	misc/xencons
PYTHON_PATCH_SCRIPTS+=	misc/xend
PYTHON_PATCH_SCRIPTS+=	misc/xensymoops
PYTHON_PATCH_SCRIPTS+=	pygrub/src/fsys/ext2/test.py
PYTHON_PATCH_SCRIPTS+=	pygrub/src/pygrub
PYTHON_PATCH_SCRIPTS+=	python/xen/util/bugtool.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/sxp.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/XendClient.py
PYTHON_PATCH_SCRIPTS+=	python/test.py
PYTHON_PATCH_SCRIPTS+=	security/python/xensec_gen/cgi-bin/policylabel.cgi
PYTHON_PATCH_SCRIPTS+=	security/python/xensec_gen/cgi-bin/policy.cgi
PYTHON_PATCH_SCRIPTS+=	security/python/xensec_gen/main.py
PYTHON_PATCH_SCRIPTS+=	security/python/setup.py
PYTHON_PATCH_SCRIPTS+=	security/xensec_gen.py
PYTHON_PATCH_SCRIPTS+=	xenmon/xenmon.py
PYTHON_PATCH_SCRIPTS+=	xentrace/xentrace_format

SUBST_CLASSES+=         paths
SUBST_STAGE.paths=      pre-configure
SUBST_FILES.paths=      ioemu/vl.c
SUBST_SED.paths=        -e "s|/usr/sbin|${PREFIX}/sbin|g"
SUBST_MESSAGE.paths=    Fixing hardcoded paths.

SUBST_CLASSES+=		pathsvar
SUBST_STAGE.pathsvar=	pre-configure
SUBST_FILES.pathsvar=	debugger/pdb/xcs.ml \
			examples/init.d/sysconfig.xendomains \
			examples/xend-config.sxp \
			python/xen/xend/server/relocate.py \
			python/xen/xend/XendRoot.py \
			security/Makefile security/python/xensec_gen/main.py \
			xenstore/Makefile xenstore/xs_lib.c
SUBST_SED.pathsvar=	-e "s|/var/lib|${VARBASE}/run|g"

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_FILES.py=		pygrub/Makefile
SUBST_FILES.py+=	python/Makefile
SUBST_FILES.py+=	security/Makefile
SUBST_SED.py=		-e "s,python,${PYTHONBIN},g"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	ioemu/configure
SUBST_FILES.conf+=	ioemu/vl.c
SUBST_FILES.conf+=	python/xen/xend/XendRoot.py
SUBST_FILES.conf+=	python/xen/xm/tests/test_create.py
SUBST_FILES.conf+=	python/xen/xm/create.py
SUBST_FILES.conf+=	security/example.txt
SUBST_FILES.conf+=	security/getlabel.sh
SUBST_FILES.conf+=	security/labelfuncs.sh
SUBST_FILES.conf+=	security/secpol_xml2bin.h
SUBST_FILES.conf+=	security/setlabel.sh
SUBST_SED.conf=		-e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	python/xen/util/auxbin.py
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},g"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		proc
SUBST_STAGE.proc=	pre-configure
SUBST_FILES.proc=	libxc/xc_misc.c
SUBST_FILES.proc+=	python/xen/xend/XendVnet.py
SUBST_FILES.proc+=	python/xen/xend/balloon.py
SUBST_FILES.proc+=	security/get_decision.c
SUBST_FILES.proc+=	security/secpol_tool.c
SUBST_FILES.proc+=	xenmon/xenbaked.c
SUBST_FILES.proc+=	xenstat/libxenstat/src/xen-interface.c
SUBST_FILES.proc+=	xenstore/xenstored_proc.h
SUBST_FILES.proc+=	xenstore/xs_lib.c
SUBST_FILES.proc+=	xentrace/xentrace.c
SUBST_SED.proc=		-e "s|/proc|/kern|g"
PROCPATH=		/kern
.else
PROCPATH=		/proc
.endif

RCD_SCRIPTS=		xend xenbackendd xendomains
FILES_SUBST+=		RCD_INTERPRETER=${PYTHONBIN:Q}
FILES_SUBST+=		PROCPATH=${PROCPATH:Q}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

XEND_SCRIPTS=		block vif-bridge

CONF_FILES=		${EGDIR}/xend-config.sxp \
			${PKG_SYSCONFDIR}/xend-config.sxp
.for s in ${XEND_SCRIPTS}
CONF_FILES_PERMS+=	${EGDIR}/${s} ${PKG_SYSCONFDIR}/scripts/${s}	\
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor

OWN_DIRS=		${PKG_SYSCONFDIR}/scripts

pre-build:
	${MKDIR} ${WRKSRC}/libxc/xen/NetBSD
	${TEST} -f ${WRKSRC}/libxc/xen/NetBSD/xenio.h || ${CP} ${FILESDIR}/xenio.h ${WRKSRC}/libxc/xen/NetBSD
	${TEST} -f ${WRKSRC}/libxc/xen/NetBSD/xenio3.h || ${CP} ${FILESDIR}/xenio3.h ${WRKSRC}/libxc/xen/NetBSD

.if ${OPSYS} == "NetBSD"
post-build:
	cd ${FILESDIR}; for src in *-nbsd; do				\
		dst="$${src%-nbsd}";					\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			-e "s|@PREFIX@|${PREFIX}|g"			\
			$$src > ${WRKSRC}/examples/$$dst;		\
	done
	${CC} ${CFLAGS}  ${LDFLAGS} \
	    -DVBD_SCRIPT=\"${PKG_SYSCONFDIR}/scripts/block\" \
	    -DLOG_FILE=\"${VARBASE}/log/xenbackendd.log\" \
	    -DPID_FILE=\"${VARBASE}/run/xenbackendd.pid\" \
	    -o ${WRKDIR}/xenbackendd.bin ${FILESDIR}/xenbackendd.c \
	    -I${WRKSRC}/libxc -L${WRKSRC}/libxc \
	    -I${WRKSRC}/xenstore -L${WRKSRC}/xenstore \
	    -lxenctrl -lxenstore

.endif

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/xenbackendd.bin ${PREFIX}/sbin/xenbackendd
	${INSTALL_DATA_DIR} ${EGDIR}
	for f in xend-config.sxp xmexample1 xmexample2 xmexample3; do	\
		${INSTALL_DATA} ${WRKSRC}/examples/$$f ${EGDIR}/$$f;	\
	done
.for s in ${XEND_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${s} ${EGDIR}/${s}
.endfor
	${RM} -rf ${PREFIX}/lib/xen

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
