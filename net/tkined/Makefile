# $NetBSD: Makefile,v 1.38 2023/01/29 21:17:31 ryoon Exp $

DISTNAME=	scotty-2.1.11
PKGNAME=	tkined-1.4.11
PKGREVISION=	13
CATEGORIES=	net tcl tk
#MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ibr.cs.tu-bs.de/projects/nm/tkined/welcome.html.orig
COMMENT=	Graphical network discovery and monitoring tool based on scotty

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib	\
			--with-tk-config=${BUILDLINK_PREFIX.tk}/lib	\
			--enable-multicast --enable-gdmo
CONFIGURE_ENV+=		TARGET=tkined

USE_LIBTOOL=	yes

DISTINFO_FILE=	${.CURDIR}/../../net/tcl-scotty/distinfo
FILESDIR=	${.CURDIR}/../../net/tcl-scotty/files
PATCHDIR=	${.CURDIR}/../../net/tcl-scotty/patches

INSTALLATION_DIRS=	${PKGMANDIR}/man1

CONFIGURE_DIRS=	unix
BUILD_DIRS=	unix
INSTALL_TARGET=	tki-install

CFLAGS+=	-DUSE_INTERP_RESULT

.include "../../net/tcl-scotty/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-install:
	${LN} -f -s tkined1.4.11 ${DESTDIR}${PREFIX}/bin/tkined
	${INSTALL_DATA} ${WRKSRC}/doc/tkined.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	chmod 644 ${DESTDIR}${PREFIX}/lib/tcl/tkined*/pkgIndex.tcl

.include "../../mk/bsd.pkg.mk"
