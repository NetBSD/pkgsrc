# $NetBSD: Makefile,v 1.25 2011/09/02 08:06:55 he Exp $
#

DISTNAME=	scotty-${DIST_VERS}
PKGNAME=	tcl-scotty-${DIST_VERS}
PKGREVISION=	5
CATEGORIES=	net tcl
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nosuchname.net/scotty/
COMMENT=	Network management extensions to TCL

LICENSE=	2-clause-bsd

BUILDLINK_API_DEPENDS.tcl+=	tcl>=8.4.6nb4

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT= destdir

DIST_VERS=	2.1.11

CONFIGURE_DIRS=	unix
BUILD_DIRS=	unix

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib	\
		--enable-multicast				\
		--enable-gdmo --without-tk-config
CONFIGURE_ENV+=	TARGET=scotty

USE_LIBTOOL=	yes
USE_TOOLS+=	lex yacc

INSTALL_TARGET= tnm-install install-man sinstall

.include "../../lang/tcl/buildlink3.mk"

post-extract:
	cd ${WRKSRC}/${BUILD_DIRS} && ${RM} -f ../doc/http.n
	cd ${WRKSRC}/${BUILD_DIRS} && ${RM} -f ../doc/tkined.1

pre-install:
	cd ${WRKSRC}/${BUILD_DIRS} && ${INSTALL} ../tnm/ntping/ntping.8 ../doc

post-install:
	cd ${DESTDIR}/${PREFIX}/bin && ${LN} -f -s scotty${DIST_VERS} scotty
	cd ${DESTDIR}/${PREFIX}/lib/tcl/tnm${DIST_VERS}; \
		sed -e 's:${DESTDIR}/::' <pkgIndex.tcl >pkgIndex.tcl.new; \
		rm -f pkgIndex.tcl; mv pkgIndex.tcl.new pkgIndex.tcl

.include "../../mk/bsd.pkg.mk"
