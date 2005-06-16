# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=		jgrasp170
PKGNAME=		jgrasp-1.7.0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.eng.auburn.edu/pub/grasp/jgrasp/
EXTRACT_SUFX=		.zip

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.jgrasp.org/
COMMENT=		IDE with support for Software Visualizations

WRKSRC=			${WRKDIR}/jgrasp
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 jdk13 jdk14
INSTALLATION_DIRS=	bin

do-configure:
	${MKDIR} ${WRKSRC}/bin/${LOWER_OPSYS}

do-build:
	${CC} ${CFLAGS} -lutil -o ${WRKSRC}/jbin/${LOWER_OPSYS}_run 	\
		${WRKSRC}/src/linux_run.c
	${CC} ${CFLAGS} -I${X11BASE}/include				\
		-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib -lX11 \
		-o ${WRKSRC}/bin/${LOWER_OPSYS}/jgrasp 			\
		${WRKSRC}/src/linux_exec.c

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME}
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME}/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME}/bin/${LOWER_OPSYS}
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME}/jbin
	cd ${WRKSRC} && ${PAX} -s ,^./.*bin/.*,, 			\
		-rw . ${PREFIX}/${PKGNAME}/
	${INSTALL_DATA} ${WRKSRC}/jbin/JGRASP__829J_6h.class		\
		${PREFIX}/${PKGNAME}/jbin/
	${INSTALL_PROGRAM} ${WRKSRC}/jbin/${LOWER_OPSYS}_run		\
		${PREFIX}/${PKGNAME}/jbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${LOWER_OPSYS}/jgrasp 		\
		${PREFIX}/${PKGNAME}/bin/${LOWER_OPSYS}/
	${LN} -s ${PREFIX}/${PKGNAME}/bin/${LOWER_OPSYS}/jgrasp		\
		${PREFIX}/bin/jgrasp

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
