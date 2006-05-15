# $NetBSD: Makefile,v 1.13 2006/05/15 19:41:45 joerg Exp $
#

DISTNAME=		jgrasp170
PKGNAME=		jgrasp-1.7.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.eng.auburn.edu/pub/grasp/jgrasp/
EXTRACT_SUFX=		.zip

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.jgrasp.org/
COMMENT=		IDE with support for Software Visualizations

WRKSRC=			${WRKDIR}/jgrasp
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 jdk14
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

pre-install:
	${RM} -f ${WRKSRC}/src/linux_exec.c.orig

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME_NOREV}
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME_NOREV}/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME_NOREV}/bin/${LOWER_OPSYS}
	${INSTALL_PROGRAM_DIR} ${PREFIX}/${PKGNAME_NOREV}/jbin
	cd ${WRKSRC} && ${PAX} -s ,^./.*bin/.*,, 			\
		-rw . ${PREFIX}/${PKGNAME_NOREV}/
	${INSTALL_DATA} ${WRKSRC}/jbin/JGRASP__829J_6h.class		\
		${PREFIX}/${PKGNAME_NOREV}/jbin/
	${INSTALL_PROGRAM} ${WRKSRC}/jbin/${LOWER_OPSYS}_run		\
		${PREFIX}/${PKGNAME_NOREV}/jbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${LOWER_OPSYS}/jgrasp 		\
		${PREFIX}/${PKGNAME_NOREV}/bin/${LOWER_OPSYS}/
	${LN} -s ${PREFIX}/${PKGNAME_NOREV}/bin/${LOWER_OPSYS}/jgrasp	\
		${PREFIX}/bin/jgrasp

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
