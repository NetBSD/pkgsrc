# $NetBSD: Makefile,v 1.35 2003/08/26 01:43:48 jschauma Exp $
#
# NOTE:	If you update this package, then you'll likely need to also update
#	the x11-links dependency in mk/buildlink2/bsd.buildlink2.mk to the
#	correct version, usually the most recent.

DISTNAME=	x11-links-0.12
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Shadow tree of links to X11R6 headers and libraries

USE_BUILDLINK2=	# defined
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined
USE_X11=	# defined

USE_X11_LINKS=			NO
_REQUIRE_BUILTIN_FREETYPE2=	YES
_REQUIRE_BUILTIN_XPM=		YES
_REQUIRE_BUILTIN_XRENDER=	YES

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
BUILDLINK_X11_SUBDIR=	share/x11-links

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/X.h)
PKG_FAIL_REASON= "${PKGNAME} requires X headers to be installed"
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	cd ${BUILDLINK_DIR} && { ${ECHO} include ; ${ECHO} lib${ABI} ; } | \
		${PAX} -rw ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	cd ${PREFIX}; ${FIND} ${BUILDLINK_X11_SUBDIR} \! -type d -print	\
		| ${SED} "s|^\./||g" | ${SORT} -u >> ${PLIST_SRC}
	${ECHO} "@unexec ${RM} -rf %D/${BUILDLINK_X11_SUBDIR}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
