# $NetBSD: Makefile,v 1.11 2003/06/23 10:12:35 seb Exp $
#

DISTNAME=	binutils-2.13.2.1
PKGREVISION=	1
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

USE_NEW_TEXINFO=	YES
USE_MAKEINFO=		YES
INFO_FILES=	as.info bfd.info binutils.info gprof.info ld.info

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-configure:
	cd ${WRKSRC};						\
	for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi	\
	  gas/doc/as.1; do					\
		${TOUCH} $${f};					\
	done

post-install:
	${FIND} ${PREFIX}/${MACHINE_GNU_PLATFORM}/lib/ldscripts -type f -print | \
		${SORT} -r | ${SED} 's;${PREFIX}/;;g' > ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
