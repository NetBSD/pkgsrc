# $NetBSD: Makefile,v 1.13 2005/05/02 17:01:34 drochner Exp $

DISTNAME=		cint5.15
PKGNAME=		cint-5.15.169
CATEGORIES=		lang
MASTER_SITES=		ftp://root.cern.ch/root/
#MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://root.cern.ch/root/Cint.html
COMMENT=		C/C++ interpreter

#same distribution file name for minor versions
DIST_SUBDIR=		${PKGNAME}
WRKSRC=			${WRKDIR}

do-build:
	@cd ${WRKDIR};						\
	case ${OPSYS} in					\
	NetBSD)							\
		${SH} ./setup platform/netbsd ;;		\
	SunOS)							\
		${SH} ./setup platform/solaris_gcc ;;		\
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

.include "../../mk/bsd.pkg.mk"
