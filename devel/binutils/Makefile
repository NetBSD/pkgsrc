# $NetBSD: Makefile,v 1.10 2003/06/08 20:17:13 fredb Exp $
#

DISTNAME=	binutils-2.13.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/directory/binutils.html
COMMENT=	GNU binary utilities

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC
PLIST_SRC+=	${PKGDIR}/PLIST.common_end

post-install:
	${FIND} ${PREFIX}/${MACHINE_GNU_PLATFORM}/lib/ldscripts -type f -print | \
		${SORT} -r | ${SED} 's;${PREFIX}/;;g' > ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
