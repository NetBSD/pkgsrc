# $NetBSD: Makefile,v 1.7 2002/12/25 16:53:51 grant Exp $
#

DISTNAME=	binutils-2.11.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/directory/binutils.html
COMMENT=	GNU binary utilities

CONFLICTS=	ddd<=3.3	# libiberty.a

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCHFILES=	binutils-NetBSD-diff-20020418.patch.bz2
PATCH_SITES=	${MASTER_SITE_LOCAL}
PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC
PLIST_SRC+=	${WRKDIR}/PLIST.common_end

post-install:
	${FIND} ${PREFIX}/${MACHINE_GNU_PLATFORM}/lib/ldscripts -type f -print | \
		${SORT} -r | ${SED} 's;${PREFIX}/;;g' > ${WRKDIR}/PLIST_DYNAMIC

.endif

.include "../../mk/bsd.pkg.mk"
