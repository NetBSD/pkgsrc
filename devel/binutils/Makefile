# $NetBSD: Makefile,v 1.19 2004/04/02 02:23:05 jlam Exp $

DISTNAME=	binutils-2.14
PKGNAME=	binutils-2.14.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/binutils.html
COMMENT=	GNU binary utilities

CONFLICTS=	avr-binutils<2.13.2.1nb1

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

USE_MAKEINFO=		yes
TEXINFO_REQD=		4.0
MAKEFLAGS+=		TEXINFO_LOCALE=no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lib-path='/lib:/usr/lib'
BINUTILS_PREFIX=	${PREFIX}/${MACHINE_GNU_PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC
PLIST_SRC+=	${PKGDIR}/PLIST.common_end

INFO_FILES=	as.info bfd.info binutils.info gprof.info ld.info

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
#
post-configure:
.for _file_ in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi gas/doc/as.1
	if [ -f ${WRKSRC}/${_file_} ]; then				\
		${TOUCH} ${WRKSRC}/${_file_};				\
	fi
.endfor

post-install:
	${FIND} ${BINUTILS_PREFIX}/lib/ldscripts -type f -print		\
		| ${SORT} -r						\
		| ${SED} 's;${PREFIX}/;;g'				\
		> ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
