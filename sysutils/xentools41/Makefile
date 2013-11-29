# $NetBSD: Makefile,v 1.40 2013/11/29 19:31:47 drochner Exp $
#
# VERSION is set in version.mk as it is shared with other packages
.include		"version.mk"

DISTNAME=		xen-${VERSION}
PKGNAME=		xentools41-${VERSION}
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/

DISTFILES=		${DISTNAME}.tar.gz
DISTFILES+=		ipxe-git-v${VERSION_IPXE}.tar.gz
SITES.ipxe-git-v${VERSION_IPXE}.tar.gz +=	http://xenbits.xensource.com/xen-extfiles/

MAINTAINER=		cegger@NetBSD.org
HOMEPAGE=		http://xen.org/
COMMENT=		Userland Tools for Xen 4.1.x

LICENSE=		gnu-gpl-v2

#DEPENDS+=		${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=		${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses

# XXX add version check: Xen requires dev86 >= 0.16.14
BUILD_DEPENDS+= dev86-[0-9]*:../../devel/dev86 # needed to build firmware
.if !exists(/usr/bin/iasl)
BUILD_DEPENDS+= acpica-utils-[0-9]*:../../sysutils/acpica-utils
.endif

PKG_SYSCONFSUBDIR=	xen

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

CONFLICTS+=		libxen-[0-9]*
CONFLICTS+=		xentools20-[0-9]*
CONFLICTS+=		xentools3*
CONFLICTS+=		xenstoretools-*

WRKSRC=			${WRKDIR}/xen-${VERSION}/tools
CHECK_PORTABILITY_SKIP=	examples/*

EGDIR=			${PREFIX}/share/examples/xen
MESSAGE_SUBST=		EGDIR=${EGDIR}

USE_TOOLS+=		perl 	#for pod2man
USE_TOOLS+=		gmake

MAKE_ENV+=		PREFIX=${prefix:Q} WRKSRC=${WRKSRC}
MAKE_ENV+=		EGDIR=${EGDIR:Q}
MAKE_ENV+=		BASH_COMPLETION_DIR=${EGDIR:Q}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}
MAKE_ENV+=		VARBASE=${VARBASE}
MAKE_ENV+=		XEN_CONFIG_DIR=${PKG_SYSCONFDIR}
MAKE_ENV+=		V=YES

#MAKE_ENV+=		INSTALL_DIR=${BSD_INSTALL_DATA_DIR}
#MAKE_ENV+=		INSTALL_DATA=${BSD_INSTALL_DATA}
#MAKE_ENV+=		INSTALL_PROG=${BSD_INSTALL_PROGRAM}

PY_PATCHPLIST=		yes
#PYTHON_PATCH_SCRIPTS+=	misc/xm
#PYTHON_PATCH_SCRIPTS+=	misc/netfix
#PYTHON_PATCH_SCRIPTS+=	misc/xen-bugtool
#PYTHON_PATCH_SCRIPTS+=	misc/xencons
#PYTHON_PATCH_SCRIPTS+=	misc/xend
#PYTHON_PATCH_SCRIPTS+=	misc/xensymoops
#PYTHON_PATCH_SCRIPTS+=	misc/xen-python-path
#PYTHON_PATCH_SCRIPTS+=	pygrub/src/pygrub
#PYTHON_PATCH_SCRIPTS+=	python/xen/util/*.py
#PYTHON_PATCH_SCRIPTS+=	python/xen/xend/*.py
#PYTHON_PATCH_SCRIPTS+=	python/xen/xm/*.py
#PYTHON_PATCH_SCRIPTS+=	python/xen/util/*.py
#PYTHON_PATCH_SCRIPTS+=	python/*.py
#PYTHON_PATCH_SCRIPTS+=	security/python/xensec_gen/cgi-bin/policy.cgi
#PYTHON_PATCH_SCRIPTS+=	security/python/xensec_gen/*.py
#PYTHON_PATCH_SCRIPTS+=	security/python/*.py
#PYTHON_PATCH_SCRIPTS+=	security/*.py
#PYTHON_PATCH_SCRIPTS+=	xenmon/*.py
#PYTHON_PATCH_SCRIPTS+=	xentrace/xentrace_format

REPLACE_PYTHON+=	python/xen/remus/*.py
REPLACE_PYTHON+=	python/xen/util/*.py
REPLACE_PYTHON+=	python/xen/xend/*.py
REPLACE_PYTHON+=	python/xen/xm/*.py
REPLACE_PYTHON+=	xenmon/xenmon.py

SUBST_CLASSES+=		pathsvar
SUBST_STAGE.pathsvar=	pre-configure
SUBST_FILES.pathsvar=	Makefile \
			examples/xend-config.sxp \
			hotplug/Linux/init.d/sysconfig.xendomains \
			python/xen/xend/XendOptions.py \
			python/xen/xend/server/relocate.py \
			python/xen/xend/tests/xend-config.sxp \
			security/Makefile \
			security/python/xensec_gen/main.py \
			xenstore/xs_lib.c
SUBST_SED.pathsvar=	-e "s|/var/lib|${VARBASE}/run|g"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf+=	python/xen/xm/create.py
SUBST_FILES.conf+=	ocaml/xenstored/define.ml
SUBST_SED.conf=		-e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g"

.include "../../mk/bsd.prefs.mk"

XEND_SCRIPTS=		block vif-bridge vif-ip qemu-ifup hotplugpath.sh

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		proc
SUBST_STAGE.proc=	pre-configure
SUBST_FILES.proc=	python/xen/xend/XendVnet.py
SUBST_FILES.proc+=	ocaml/xenstored/define.ml
SUBST_SED.proc=		-e "s|/proc|/kern|g"
PROCPATH=		/kern
.else
PROCPATH=		/proc
.endif

SUBST_CLASSES+=		procdev
SUBST_STAGE.procdev=	pre-configure
SUBST_FILES.procdev=	ocaml/xenstored/define.ml
.if ${OPSYS} == "NetBSD"
SUBST_SED.procdev=	-e "s|@PROCDEV@|/dev|g"
.else
SUBST_SED.procdev=	-e "s|@PROCDEV@|/proc/xen|g"
.endif

RCD_SCRIPTS=		xen-watchdog xencommons xend xendomains
FILES_SUBST+=		RCD_INTERPRETER=${PYTHONBIN:Q}
FILES_SUBST+=		PROCPATH=${PROCPATH:Q}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
FILES_SUBST+=		PREFIX=${PREFIX:Q}

BLKTAP_FILES=		blk_netbsd.c blktapctrl_netbsd.c

CONF_FILES+=		${EGDIR}/xend-config.sxp ${PKG_SYSCONFDIR}/xend-config.sxp
CONF_FILES+=		${EGDIR}/formats ${PKG_SYSCONFDIR}/formats
CONF_FILES+=		${EGDIR}/xm-config.xml ${PKG_SYSCONFDIR}/xm-config.xml

OWN_DIRS=		${PKG_SYSCONFDIR}/scripts ${VARBASE}/log/xen ${VARBASE}/lib

.for s in ${XEND_SCRIPTS}
CONF_FILES_PERMS+=	${EGDIR}/scripts/${s} ${PKG_SYSCONFDIR}/scripts/${s} \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
.endfor

pre-build:
	rm -f ${WRKSRC}/check/check_x11_devel
.for s in ${BLKTAP_FILES}
	${CP} ${FILESDIR}/${s} ${WRKSRC}/blktap/drivers/
.endfor
	pod2man ${WRKSRC}/../docs/man/xend-config.sxp.pod.5  |\
	    ${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
	    >${WRKDIR}/xend-config.sxp.5
	pod2man ${WRKSRC}/../docs/man/xmdomain.cfg.pod.5 |\
	    ${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
	    >${WRKDIR}/xmdomain.cfg.5
	pod2man ${WRKSRC}/../docs/man/xm.pod.1 |\
	    ${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
	    >${WRKDIR}/xm.1

INSTALLATION_DIRS=	${EGDIR} ${PKGMANDIR}/man5

post-install:
	for f in xend-config.sxp xmexample1 xmexample2 xmexample3; do \
		${INSTALL_DATA} ${WRKSRC}/examples/$$f ${DESTDIR}${EGDIR}/$$f;	\
	done
	${INSTALL_DATA} ${WRKDIR}/xend-config.sxp.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKDIR}/xmdomain.cfg.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKDIR}/xm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=	-Dshm_open=open -Dshm_unlink=unlink
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
EXTRA_HOSTCFLAGS+=	-Wno-error=ignored-attributes
EXTRA_CFLAGS+=	-Wno-error=ignored-attributes -no-integrated-as \
		-Wno-error=tautological-compare -Wno-error=null-dereference \
		-Wno-error=empty-body -Wno-error=self-assign \
		-Wno-error=sometimes-uninitialized -Wno-error=unused-function
BUILDLINK_TRANSFORM+=	rm:-falign-jumps=1 rm:-falign-loops=1 \
			rm:-mpreferred-stack-boundary=2
.endif

MAKE_ENV+=	EXTRA_HOSTCFLAGS=${EXTRA_HOSTCFLAGS:Q} EXTRA_CFLAGS=${EXTRA_CFLAGS:Q}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../devel/SDL/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
