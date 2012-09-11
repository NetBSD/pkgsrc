# $NetBSD: Makefile,v 1.3 2012/09/11 22:37:13 asau Exp $
#

DISTNAME=	libmicro-${LIBMICRO_VERSION}
CATEGORIES=	benchmarks
MASTER_SITES=	http://hub.opensolaris.org/bin/download/Project+libmicro/Source+Archives/

LIBMICRO_VERSION=	0.4.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hub.opensolaris.org/bin/view/Project+libmicro/
COMMENT=	Set of utilities to benchmark productivity of system calls

LICENSE=	cddl-1.0

WRKSRC=		${WRKDIR}/libMicro-${LIBMICRO_VERSION}

USE_TOOLS=	gmake tee
BUILD_TARGET=	default

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	libexec/${PKGBASE}
INSTALLATION_DIRS+=	libexec/${PKGBASE}/bin
INSTALLATION_DIRS+=	libexec/${PKGBASE}/bin-${MACHINE_ARCH}

LIBMICRO_BASE=		${PREFIX}/libexec/${PKGBASE}

SUBST_CLASSES+=		fix-arch
SUBST_MESSAGE.fix-arch=	Fix machine architecture path
SUBST_STAGE.fix-arch=	pre-configure
SUBST_FILES.fix-arch=	Makefile bench.sh wrapper.sh
SUBST_SED.fix-arch=	-e 's|@@MACHINE_ARCH@@|${MACHINE_ARCH:Q}|'

post-build:
	${SED}  -e 's|@@DESTDIR@@|${DESTDIR:Q}|'	\
		-e 's|@@PREFIX@@|${PREFIX:Q}|'		\
		-e 's|@@PKGBASE@@|${PKGBASE:Q}|'	\
		${FILESDIR}/run-libmicro > ${WRKDIR}/run-libmicro

do-install:
	cd ${WRKSRC}/bin;						\
	for f in *; do 							\
		${INSTALL_PROGRAM} ${WRKSRC}/bin-${MACHINE_ARCH}/$$f	\
		    ${DESTDIR}${LIBMICRO_BASE}/bin-${MACHINE_ARCH};	\
	done
	cd ${DESTDIR}${LIBMICRO_BASE}/bin-${MACHINE_ARCH};		\
	for f in *; do							\
		${LN} -s ../wrapper ../bin/$$f; 			\
	done
	${INSTALL_PROGRAM} ${WRKSRC}/bin-${MACHINE_ARCH}/exec_bin	\
		${DESTDIR}${LIBMICRO_BASE}/bin-${MACHINE_ARCH}
	${INSTALL_SCRIPT}  ${WRKSRC}/bench		\
		${DESTDIR}${LIBMICRO_BASE}
	${INSTALL_SCRIPT}  ${WRKSRC}/wrapper		\
		${DESTDIR}${LIBMICRO_BASE}
	${INSTALL_SCRIPT}  ${WRKSRC}/multiview		\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/run-libmicro	\
		${DESTDIR}${PREFIX}/bin

benchmark:
	cd ${WRKSRC}; ./bench | ${TEE} libmicro.output

results:
	${MKDIR} /tmp/benches/`domainname`
	cd ${WRKSRC}; \
	./multiview libmicro.output > /tmp/benches/`domainname`/libmicro.`uname`-`uname -m`-`uname -r`.`hostname`.html

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
