# $NetBSD: Makefile,v 1.4 2002/08/25 19:22:22 jlam Exp $
#

DISTNAME=	binutils-2.11.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/directory/binutils.html
COMMENT=	GNU binary utilities

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCHFILES=	binutils-NetBSD-diff-20020418.patch.bz2
PATCH_SITES=	${MASTER_SITE_LOCAL}
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC ${PKGDIR}/PLIST

post-install:
	${FIND} ${PREFIX}/${MACHINE_GNU_PLATFORM}/lib/ldscripts -type f -print | \
		${SORT} -r | ${SED} 's;${PREFIX}/;;g' > ${WRKDIR}/PLIST_DYNAMIC

.elif ${OPSYS} == "SunOS"
PLIST_SRC=	${PKGDIR}/PLIST.${OPSYS}
.endif

.include "../../mk/bsd.pkg.mk"
