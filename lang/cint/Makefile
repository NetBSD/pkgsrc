# $NetBSD: Makefile,v 1.8 2001/05/09 15:14:16 agc Exp $

DISTNAME=		cint5.14
PKGNAME=		cint-5.14.40
NO_WRKSUBDIR=		yes
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		drochner@netbsd.org
HOMEPAGE=		http://root.cern.ch/root/Cint.html
COMMENT=		C/C++ interpreter

#same distribution file name for minor versions
DIST_SUBDIR=		${PKGNAME}

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
