# $NetBSD: Makefile,v 1.18 1999/01/26 06:56:54 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/20 10:33:35 jkh Exp
#

DISTNAME=		tcl8.0p2
PKGNAME=		tcl-8.0p2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.scriptics.com/

WRKSRC=			${WRKDIR}/tcl8.0/unix
GNU_CONFIGURE=		yes

# let libtool deal with shared libraries
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-shared

# If the build system supports shared objects, enable them in tcl.
# libtermcap was chosen as it doesn't change version numbers frequently.
.if exists(/usr/lib/libtermcap.so.0.0)
post-configure:
	@${ECHO} "Enabling shared object support in ${PKGNAME}"
	cd ${WRKSRC};							\
		${MV} tclConfig.sh tclConfig.sh.orig;			\
		${SED} -e 's/TCL_SHARED_BUILD=.*/TCL_SHARED_BUILD=1/'	\
			-e 's/TCL_LIB_FILE=.*/TCL_LIB_FILE=libtcl80.so.1.0/' \
			tclConfig.sh.orig > tclConfig.sh
.endif

test:
	cd ${WRKSRC} && ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
