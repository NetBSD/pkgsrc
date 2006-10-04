# $NetBSD: Makefile,v 1.16 2006/10/04 21:53:18 wiz Exp $
#

DISTNAME=	scotty-2.1.11
PKGNAME=	tkined-1.4.11
PKGREVISION=	3
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.nosuchname.net/scotty/
COMMENT=	Graphical network discovery and monitoring tool based on scotty

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk-config=${BUILDLINK_PREFIX.tk}/lib	\
		--enable-multicast --enable-gdmo
CONFIGURE_ENV+=	TARGET=tkined

USE_LIBTOOL=	yes

DISTINFO_FILE=	${.CURDIR}/../../net/tcl-scotty/distinfo
FILESDIR=	${.CURDIR}/../../net/tcl-scotty/files
PATCHDIR=	${.CURDIR}/../../net/tcl-scotty/patches

INSTALLATION_DIRS=	man/man1

.include "../../net/tcl-scotty/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

do-install:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} tki-install
	${INSTALL_DATA} ${WRKSRC}/../doc/tkined.1 ${PREFIX}/man/man1

post-install:
	cd ${PREFIX}/bin && ${LN} -f -s tkined1.4.11 tkined

.include "../../mk/bsd.pkg.mk"
