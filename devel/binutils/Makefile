# $NetBSD: Makefile,v 1.34 2008/02/28 19:06:34 tnn Exp $

DISTNAME=	binutils-2.17
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/binutils.html
COMMENT=	GNU binary utilities

CONFLICTS=	avr-binutils<2.13.2.1nb1

NOT_FOR_PLATFORM=	Darwin-*-* Interix-*-*

USE_PKGLOCALEDIR=	yes
REPLACE_LOCALEDIR_PATTERNS+=	Make-in

USE_TOOLS+=		makeinfo
TEXINFO_REQD=		4.0
MAKEFLAGS+=		TEXINFO_LOCALE=no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lib-path='/lib:/usr/lib'
GNU_PROGRAM_PREFIX?=	gnu-
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX
BINUTILS_PREFIX=	${PREFIX}/${MACHINE_GNU_PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC
PLIST_SRC+=	${PKGDIR}/PLIST.common_end

INFO_FILES=	# PLIST

# gprof (XXX: and others?) cannot be built on all platforms
#
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "IRIX"
PLIST_SUBST+=	NO_GPROF="@comment "
.else
PLIST_SUBST+=	NO_GPROF=""
.endif

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
#
post-configure:
.for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi gas/doc/as.1
	if [ -f ${WRKSRC}/${f} ]; then					\
		touch ${WRKSRC}/${f};					\
	fi
.endfor

post-install:
	find ${BINUTILS_PREFIX}/lib/ldscripts -type f -print		\
		| sort -r						\
		| sed 's;${PREFIX}/;;g'					\
		> ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
