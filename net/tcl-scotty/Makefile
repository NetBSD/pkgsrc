# $NetBSD: Makefile,v 1.39 2016/06/02 12:25:47 hauke Exp $
#

DISTNAME=	scotty-${DIST_VERS}
PKGNAME=	tcl-scotty-${DIST_VERS}
PKGREVISION=	12
CATEGORIES=	net tcl
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ibr.cs.tu-bs.de/projects/scotty/
COMMENT=	Network management extensions to TCL

MAKE_JOBS_SAFE=	no

LICENSE=	2-clause-bsd

DIST_VERS=	2.1.11

CONFIGURE_DIRS=	unix
BUILD_DIRS=	unix

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib	\
		--enable-multicast				\
		--enable-gdmo --without-tk-config
CONFIGURE_ENV+=	TARGET=scotty

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q} GDMO_LIBS=

USE_LIBTOOL=	yes
USE_TOOLS+=	lex yacc

PLIST_SUBST+=	MACHINE="${MACHINE}"

INSTALL_TARGET= tnm-install install-man sinstall

SPECIAL_PERMS+=	bin/ntping ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	bin/straps ${SETUID_ROOT_PERMS}

post-extract:
	cd ${WRKSRC}/${BUILD_DIRS} && ${RM} -f ../doc/http.n

pre-install:
	cd ${WRKSRC}/${BUILD_DIRS} && ${RM} -f ../doc/tkined.1
	cd ${WRKSRC}/${BUILD_DIRS} && ${INSTALL} ../tnm/ntping/ntping.8 ../doc

post-install:
	cd ${DESTDIR}/${PREFIX}/bin && ${LN} -f -s scotty${DIST_VERS} scotty
	cd ${DESTDIR}/${PREFIX}/lib/tcl/tnm${DIST_VERS}; umask 022; \
		sed -e 's:${DESTDIR}/::' <pkgIndex.tcl >pkgIndex.tcl.new; \
		rm -f pkgIndex.tcl; mv pkgIndex.tcl.new pkgIndex.tcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
