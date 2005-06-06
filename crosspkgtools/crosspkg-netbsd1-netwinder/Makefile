# $NetBSD: Makefile,v 1.1.1.1 2005/06/06 22:43:10 kristerw Exp $

DISTNAME=	crosspkg-netbsd1-netwinder-1.6.2
CATEGORIES=     crosspkgtools
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-1.6.2/netwinder/binary/sets/
EXTRACT_SUFX=	.tgz
DISTFILES=	base.tgz comp.tgz etc.tgz games.tgz kern-GENERIC.tgz man.tgz \
		misc.tgz text.tgz xbase.tgz xcomp.tgz xcontrib.tgz xfont.tgz \
		xmisc.tgz \
		gnusrc.tgz sharesrc.tgz src.tgz syssrc.tgz xsrc.tgz

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.df.lth.se/~cato/kwacross/
COMMENT=	Files neccessary to cross-build NetBSD/netwinder-1.6.x programs

DEPENDS+=	kwacross-netbsd1-arm-2*:../../crosspkgtools/kwacross-netbsd1-arm

DIST_SUBDIR=	${PKGNAME_NOREV}
SRC_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-1.6.2/source/sets/
SITES_gnusrc.tgz=	${SRC_SITES}
SITES_sharesrc.tgz=	${SRC_SITES}
SITES_src.tgz=		${SRC_SITES}
SITES_syssrc.tgz=	${SRC_SITES}
SITES_xsrc.tgz=		${SRC_SITES}

EXTRACT_ONLY=	# empty
NO_BUILD=	YES

NO_PACKAGE=	"needs work to function properly as a binary package"

# Dynamically generate the PLIST from the installed files.
CROSSFS_PLIST_FILES= \
	(cd ${PREFIX};  ${FIND} crossfs/netbsd1-netwinder \! -type d -print ) \
	| ${SORT} -u
CROSSFS_PLIST_DIRS= \
	(cd ${PREFIX};  ${FIND} crossfs/netbsd1-netwinder -type d -print ) \
	| ${SED} -e "s,^,@unexec ${RMDIR} -p %D/,"			\
		 -e "s,$$, 2>/dev/null || ${TRUE},"			\
	| ${SORT} -ur
GENERATE_PLIST+=	${CROSSFS_PLIST_FILES}; ${CROSSFS_PLIST_DIRS};

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/crossfs/netbsd1-netwinder
	cd ${PREFIX}/crossfs/netbsd1-netwinder && 		\
		tar zxfp ${_DISTDIR}/base.tgz && 		\
		tar zxfp ${_DISTDIR}/comp.tgz && 		\
		tar zxfp ${_DISTDIR}/etc.tgz && 		\
		tar zxfp ${_DISTDIR}/games.tgz && 		\
		tar zxfp ${_DISTDIR}/kern-GENERIC.tgz && 	\
		tar zxfp ${_DISTDIR}/man.tgz && 		\
		tar zxfp ${_DISTDIR}/misc.tgz && 		\
		tar zxfp ${_DISTDIR}/text.tgz && 		\
		tar zxfp ${_DISTDIR}/xbase.tgz && 		\
		tar zxfp ${_DISTDIR}/xcomp.tgz && 		\
		tar zxfp ${_DISTDIR}/xcontrib.tgz && 		\
		tar zxfp ${_DISTDIR}/xfont.tgz && 		\
		tar zxfp ${_DISTDIR}/xmisc.tgz && 		\
		tar zxfp ${_DISTDIR}/gnusrc.tgz && 		\
		tar zxfp ${_DISTDIR}/sharesrc.tgz && 		\
		tar zxfp ${_DISTDIR}/src.tgz && 		\
		tar zxfp ${_DISTDIR}/syssrc.tgz
	cd ${PREFIX}/crossfs/netbsd1-netwinder/usr && 		\
		tar zxfp ${_DISTDIR}/xsrc.tgz
	# XXX These should be done in some kind of installation script
	# and should not be added in binary packages.
	${CP} /etc/resolv.conf ${PREFIX}/crossfs/netbsd1-netwinder/etc/resolv.conf
	${RM}  ${PREFIX}/crossfs/netbsd1-netwinder/etc/localtime
	${CP} /etc/localtime ${PREFIX}/crossfs/netbsd1-netwinder/etc/localtime

.include "../../mk/bsd.pkg.mk"
