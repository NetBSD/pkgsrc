# $NetBSD: Makefile,v 1.17 2002/09/20 23:53:32 jlam Exp $
#
# NOTE:	If you update this package, then you'll likely need to also update
#	the x11-links dependency in mk/x11.buildlink.mk and in
#	mk/buildlink2/bsd.buidlink2.mk to the correct version, usually the
#	most recent.

DISTNAME=	x11-links-0.8
CATEGORIES=	pkgtools x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	shadow tree of links to X11R6 headers and libraries

USE_BUILDLINK2=	# defined
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
WRKSRC=		${WRKDIR}
NO_BUILD=	# defined
NO_MTREE=	# defined
USE_X11=	# defined

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
BUILDLINK_X11_SUBDIR=	share/x11-links

_FOR_X11_LINKS_ONLY=-	# needed to use x11-links/buildlink.mk

.include "../../mk/bsd.prefs.mk"
   
.if !exists(${X11BASE}/include/X11/X.h)
IGNORE=         "x11-links requires X headers to be installed"
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	cd ${BUILDLINK_DIR} &&						\
		${PAX} -rw include lib ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${BUILDLINK_X11_SUBDIR}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	cd ${PREFIX}; ${FIND} ${BUILDLINK_X11_SUBDIR} \! -type d -print	\
		| ${SED} "s|^\./||g" | ${SORT} -u >> ${PLIST_SRC}
	${ECHO} "@unexec ${RM} -rf %D/${BUILDLINK_X11_SUBDIR}" >> ${PLIST_SRC}

.if !empty(X11BASE:M*openwin)
.  include "openwin.buildlink2.mk"
.else
.  include "xfree.buildlink2.mk"
.endif
.include "../../mk/bsd.pkg.mk"
