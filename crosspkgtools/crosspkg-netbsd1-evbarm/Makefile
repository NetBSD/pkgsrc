# $NetBSD: Makefile,v 1.6 2006/08/24 18:28:38 kristerw Exp $

DISTNAME=	crosspkg-netbsd1-evbarm-1.6.2
CATEGORIES=     crosspkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD-archive/NetBSD-1.6.2/evbarm/binary/sets/
EXTRACT_SUFX=	.tgz
DISTFILES=	base.tgz comp.tgz etc.tgz games.tgz kern-INTEGRATOR.tgz man.tgz \
		misc.tgz text.tgz xbase.tgz xcomp.tgz xcontrib.tgz xfont.tgz \
		xmisc.tgz \
		gnusrc.tgz sharesrc.tgz src.tgz syssrc.tgz xsrc.tgz

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.df.lth.se/~cato/kwacross/
COMMENT=	Files neccessary to cross build NetBSD/evbarm-1.6.x programs

DEPENDS+=	kwacross-netbsd1-arm-2*:../../crosspkgtools/kwacross-netbsd1-arm

DIST_SUBDIR=	${PKGNAME_NOREV}
SRC_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/NetBSD-1.6.2/source/sets/
SITES.gnusrc.tgz=	${SRC_SITES}
SITES.sharesrc.tgz=	${SRC_SITES}
SITES.src.tgz=		${SRC_SITES}
SITES.syssrc.tgz=	${SRC_SITES}
SITES.xsrc.tgz=		${SRC_SITES}

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
USE_TOOLS+=	tar

NO_PACKAGE=	needs work to function properly as a binary package

# Dynamically generate the PLIST from the installed files.
CROSSFS_PLIST_FILES_CMD= \
	(cd ${PREFIX} && ${FIND} crossfs/netbsd1-evbarm \! -type d -print ) \
	| ${SORT} -u
CROSSFS_PLIST_DIRS_CMD= \
	(cd ${PREFIX} && ${FIND} crossfs/netbsd1-evbarm -type d -print ) \
	| ${SED} -e "s,^,@unexec ${RMDIR} -p %D/,"			\
		 -e "s,\$$, 2>/dev/null || ${TRUE},"			\
	| ${SORT} -ur
GENERATE_PLIST+=	${CROSSFS_PLIST_FILES_CMD};
GENERATE_PLIST+=	${CROSSFS_PLIST_DIRS_CMD};

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/crossfs/netbsd1-evbarm
	cd ${PREFIX}/crossfs/netbsd1-evbarm && 			\
		${TAR} zxfp ${_DISTDIR}/base.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/comp.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/etc.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/games.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/kern-INTEGRATOR.tgz && 	\
		${TAR} zxfp ${_DISTDIR}/man.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/misc.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/text.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/xbase.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/xcomp.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/xcontrib.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/xfont.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/xmisc.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/gnusrc.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/sharesrc.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/src.tgz && 		\
		${TAR} zxfp ${_DISTDIR}/syssrc.tgz
	cd ${PREFIX}/crossfs/netbsd1-evbarm/usr && 		\
		${TAR} zxfp ${_DISTDIR}/xsrc.tgz
	# XXX These should be done in some kind of installation script
	# and should not be added in binary packages.
	${CP} /etc/resolv.conf ${PREFIX}/crossfs/netbsd1-evbarm/etc/resolv.conf
	${RM}  ${PREFIX}/crossfs/netbsd1-evbarm/etc/localtime
	${CP} /etc/localtime ${PREFIX}/crossfs/netbsd1-evbarm/etc/localtime

.include "../../mk/bsd.pkg.mk"
