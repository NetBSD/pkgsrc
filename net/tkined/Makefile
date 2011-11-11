# $NetBSD: Makefile,v 1.20 2011/11/11 19:17:11 joerg Exp $
#

DISTNAME=	scotty-2.1.11
PKGNAME=	tkined-1.4.11
PKGREVISION=	3
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nosuchname.net/scotty/
COMMENT=	Graphical network discovery and monitoring tool based on scotty

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk-config=${BUILDLINK_PREFIX.tk}/lib	\
		--enable-multicast --enable-gdmo
CONFIGURE_ENV+=	TARGET=tkined

USE_LIBTOOL=	yes

DISTINFO_FILE=	${.CURDIR}/../../net/tcl-scotty/distinfo
FILESDIR=	${.CURDIR}/../../net/tcl-scotty/files
PATCHDIR=	${.CURDIR}/../../net/tcl-scotty/patches

INSTALLATION_DIRS=	${PKGMANDIR}/man1

CONFIGURE_DIRS=	unix
BUILD_DIRS=	unix
INSTALL_TARGET=	tki-install

.include "../../net/tcl-scotty/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-install:
	${LN} -f -s tkined1.4.11 ${DESTDIR}${PREFIX}/bin/tkined
	${INSTALL_DATA} ${WRKSRC}/doc/tkined.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
