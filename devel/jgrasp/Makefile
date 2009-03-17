# $NetBSD: Makefile,v 1.20 2009/03/17 21:40:45 darcy Exp $
#

DISTNAME=		jgrasp170
PKGNAME=		jgrasp-1.7.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.eng.auburn.edu/pub/grasp/jgrasp/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jgrasp.org/
COMMENT=		IDE with support for Software Visualizations

WRKSRC=			${WRKDIR}/jgrasp
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 jdk14
INSTALLATION_DIRS=	bin

USE_TOOLS+=		pax

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
LIBS+=	-lutil
.endif

do-configure:
	${MKDIR} ${WRKSRC}/bin/${LOWER_OPSYS}

do-build:
	${CC} ${CFLAGS} ${LIBS} -o ${WRKSRC}/jbin/${LOWER_OPSYS}_run 	\
		${WRKSRC}/src/linux_run.c
	${CC} ${CFLAGS} -I${X11BASE}/include				\
		-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib -lX11 \
		-o ${WRKSRC}/bin/${LOWER_OPSYS}/jgrasp 			\
		${WRKSRC}/src/linux_exec.c

pre-install:
	${RM} -f ${WRKSRC}/src/linux_exec.c.orig

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/bin
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/bin/${LOWER_OPSYS}
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/jbin
	cd ${WRKSRC} && pax -s ,^./.*bin/.*,, 			\
		-rw . ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/
	${INSTALL_DATA} ${WRKSRC}/jbin/JGRASP__829J_6h.class		\
		${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/jbin/
	${INSTALL_PROGRAM} ${WRKSRC}/jbin/${LOWER_OPSYS}_run		\
		${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/jbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${LOWER_OPSYS}/jgrasp 		\
		${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/bin/${LOWER_OPSYS}/
	${LN} -s ${PREFIX}/${PKGNAME_NOREV}/bin/${LOWER_OPSYS}/jgrasp	\
		${DESTDIR}${PREFIX}/bin/jgrasp

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
