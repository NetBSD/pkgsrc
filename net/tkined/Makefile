# $NetBSD: Makefile,v 1.11 2004/06/05 04:10:21 minskim Exp $
#

DISTNAME=	scotty-2.1.11
PKGNAME=	tkined-1.4.11
PKGREVISION=	1
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://wwwhome.cs.utwente.nl/~schoenw/scotty/
COMMENT=	Graphical network discovery and monitoring tool based on scotty

DEPENDS+=	tcl-scotty>=2.1.11:../../net/tcl-scotty

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
USE_BUILDLINK3=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk-config=${BUILDLINK_PREFIX.tk}/lib	\
		--enable-multicast --enable-gdmo
CONFIGURE_ENV+=	TARGET=tkined

USE_LIBTOOL=	yes

DISTINFO_FILE=	${.CURDIR}/../../net/tcl-scotty/distinfo
FILESDIR=	${.CURDIR}/../../net/tcl-scotty/files
PATCHDIR=	${.CURDIR}/../../net/tcl-scotty/patches

.include "../../x11/tk/buildlink3.mk"

do-install:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} tki-install
	${INSTALL_DATA} ${WRKSRC}/../doc/tkined.1 ${PREFIX}/man/man1

post-install:
	cd ${PREFIX}/bin && ${LN} -f -s tkined1.4.11 tkined

.include "../../mk/bsd.pkg.mk"
