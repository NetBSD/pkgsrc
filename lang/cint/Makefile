# $NetBSD: Makefile,v 1.20 2006/05/26 12:30:15 drochner Exp $

DISTNAME=		cint5.15
PKGNAME=		cint-5.15.174
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://root.cern.ch/root/
#MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://root.cern.ch/root/Cint.html
COMMENT=		C/C++ interpreter

#same distribution file name for minor versions
DIST_SUBDIR=		${PKGNAME_NOREV}
WRKSRC=			${WRKDIR}
GCC_REQD+=		3.0
PTHREAD_OPTS+=	native
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
PLIST_SUBST+= HAVE_THR=""
.else
PLIST_SUBST+= HAVE_THR="@comment "
.endif

INSTALLATION_DIRS=	bin
USE_LANGUAGES+=		c++

post-extract:
	${FIND} -d ${WRKSRC} -type d -name CVS -exec ${RM} -rf {} \;
	${FIND} ${WRKSRC} -type f -name .cvsignore -exec ${RM} -f {} \;

do-build:
	cd ${WRKDIR};						\
	case ${OPSYS} in					\
	NetBSD)							\
		${SH} ./setup platform/netbsd ;;		\
	SunOS)							\
		${SH} ./setup platform/solaris_gcc ;;		\
	*)							\
		${ECHO} 'not yet ported to ${OPSYS}'; exit 1 ;;	\
	esac

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/cint
	${INSTALL_PROGRAM} ${WRKDIR}/cint ${PREFIX}/cint
	${INSTALL_PROGRAM} ${WRKDIR}/makecint ${PREFIX}/cint
	${SED} "s;XXXPREFIXXXX;${PREFIX};g" <${FILESDIR}/cint.sh >${PREFIX}/bin/cint
	${CHMOD} +x ${PREFIX}/bin/cint
	${LN} ${PREFIX}/bin/cint ${PREFIX}/bin/makecint
	${INSTALL_DATA} ${WRKDIR}/MAKEINFO ${PREFIX}/cint
	${CP} -r ${WRKDIR}/include ${WRKDIR}/stl ${PREFIX}/cint
	${RM} ${PREFIX}/cint/include/Makeit ${PREFIX}/cint/include/make*
	${INSTALL_DATA_DIR} ${PREFIX}/cint/lib
	${CP} -r ${WRKDIR}/lib/prec_stl ${PREFIX}/cint/lib
	${INSTALL_DATA} ${WRKDIR}/G__ci.h ${PREFIX}/cint
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/bytecode.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/cint.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/cintapi.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/extlib.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/ifdef.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/limitati.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/limitnum.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/makecint.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/message.txt ${PREFIX}/share/doc/cint
	${INSTALL_DATA} ${WRKSRC}/doc/ref.txt ${PREFIX}/share/doc/cint
	${INSTALL_MAN} ${WRKSRC}/doc/man1/cint.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man1/makecint.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man2/garbage.2 ${PREFIX}/man/man2
	${INSTALL_MAN} ${WRKSRC}/doc/man2/security.2 ${PREFIX}/man/man2
	${INSTALL_MAN} ${WRKSRC}/doc/man2/unique.2 ${PREFIX}/man/man2
	${INSTALL_MAN} ${WRKSRC}/doc/man3/array.h.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/man3/fft.h.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/man3/statistics.h.3 ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
