# $NetBSD: Makefile,v 1.17 2003/09/19 13:00:43 wiz Exp $
#

DISTNAME=	binutils-2.14
PKGNAME=	binutils-2.14.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/binutils.html
COMMENT=	GNU binary utilities

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_MAKEINFO=		YES
USE_PKGLOCALEDIR=	YES

TEXINFO_REQD=		4.0

CONFIGURE_ARGS+=	--with-lib-path='/lib:/usr/lib'

CONFLICTS=	avr-binutils<2.13.2.1nb1

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC
PLIST_SRC+=	${PKGDIR}/PLIST.common_end

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
