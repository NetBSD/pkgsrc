# $NetBSD: Makefile,v 1.6 2001/12/08 23:15:36 kristerw Exp $
#
# NOTE:	If you update this package, then you'll likely need to also update
#	the x11-links dependency in x11.buildlink.mk to the correct version,
#	usually the most recent.

DISTNAME=	x11-links-0.5
CATEGORIES=	pkgtools x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	shadow tree of links to X11R6 headers and libraries

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
WRKSRC=		${WRKDIR}
NO_BUILD=	# defined
NO_MTREE=	# defined
USE_X11=	# defined

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
BUILDLINK_X11_SUBDIR=	share/x11-links

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	cd ${BUILDLINK_DIR} &&						\
		${PAX} -rw include lib ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	cd ${PREFIX}; ${FIND} ${BUILDLINK_X11_SUBDIR} \! -type d -print	\
		| ${SED} "s|^\./||g" | ${SORT} -u >> ${PLIST_SRC}
	${ECHO} "@unexec ${RM} -rf %D/${BUILDLINK_X11_SUBDIR}" >> ${PLIST_SRC}

.include "buildlink.mk"
.include "../../mk/bsd.pkg.mk"
