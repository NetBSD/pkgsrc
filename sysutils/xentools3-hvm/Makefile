# $NetBSD: Makefile,v 1.1.1.1 2007/06/14 19:42:12 bouyer Exp $
#

VERSION=		3.1.0
DISTNAME=		xen-${VERSION}-src
PKGNAME=		xentools3-hvm-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cl.cam.ac.uk/research/srg/netos/xen/downloads/ \
			http://bits.xensource.com/oss-xen/release/${VERSION}/src.tgz/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.cl.cam.ac.uk/research/srg/netos/xen/
COMMENT=		Tools for Virtual Machine Extensions support in Xen

BUILD_DEPENDS+=	dev86-[0-9]*:../../devel/dev86 # needed to build firmware

PKG_SYSCONFSUBDIR=	xen

ONLY_FOR_PLATFORM=	Linux-2.[46]*-i386 NetBSD-*-i386

CONFLICTS=		xentools30-*

WRKSRC=			${WRKDIR}/xen-${VERSION}-src/tools
CHECK_PORTABILITY_SKIP+=	examples/* xm-test/ramdisk/make-release.sh

EGDIR=			${PREFIX}/share/examples/xen
MESSAGE_SUBST=		EGDIR=${EGDIR}

USE_TOOLS+=		perl
USE_TOOLS+=		gmake
MAKE_ENV+=		EGDIR=${EGDIR:Q}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}
MAKE_ENV+=		XEN_TARGET_ARCH="x86_32"
PYTHON_VERSIONS_ACCEPTED= 24 23

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	ioemu/vl.c
SUBST_SED.paths=	-e "s|/usr/sbin|${PREFIX}/sbin|g"
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_FILES.py=		../xen/include/public/foreign/Makefile
SUBST_SED.py=		-e "s,python,${PYTHONBIN},g"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	ioemu/configure
SUBST_FILES.conf+=	ioemu/vl.c
SUBST_SED.conf=		-e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	python/xen/util/auxbin.py
SUBST_FILES.prefix=	ioemu/vl.c
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},g"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PROCPATH=		/kern
.else
PROCPATH=		/proc
.endif

pre-build:
	${MKDIR} ${WRKSRC}/libxc/xen/NetBSD
	${TEST} -f ${WRKSRC}/libxc/xen/NetBSD/xenio.h || ${CP} ${FILESDIR}/xenio.h ${WRKSRC}/libxc/xen/NetBSD
	${TEST} -f ${WRKSRC}/libxc/xen/NetBSD/xenio3.h || ${CP} ${FILESDIR}/xenio3.h ${WRKSRC}/libxc/xen/NetBSD
	${CP} ${FILESDIR}/NetBSD.mk ${WRKSRC}/../config/

.if ${OPSYS} == "NetBSD"
post-build:
	cd ${FILESDIR}; for src in *-nbsd; do				\
		dst="$${src%-nbsd}";					\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			-e "s|@PREFIX@|${PREFIX}|g"			\
			$$src > ${WRKSRC}/examples/$$dst;		\
	done
.endif

post-install:
	for f in hvm; do \
		${INSTALL_DATA} ${WRKSRC}/examples/$$f ${EGDIR}/$$f;	\
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../sysutils/xentools3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
