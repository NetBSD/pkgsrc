# $NetBSD: Makefile,v 1.8 2003/12/18 09:52:32 wiz Exp $
#

DISTNAME=	scotty-2.1.11
PKGNAME=	tkined-1.4.11
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://wwwhome.cs.utwente.nl/~schoenw/scotty/
COMMENT=	Graphical network discovery and monitoring tool based on scotty

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	tcl-scotty>=2.1.11:../../net/tcl-scotty

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --with-tcl-config=${PREFIX}/lib --enable-multicast \
		--enable-gdmo --with-tk-config=${PREFIX}/lib
CONFIGURE_ENV+=	TARGET=tkined

USE_LIBTOOL=	yes

FILESDIR=	${.CURDIR}/../../net/tcl-scotty/files
PATCHDIR=	${.CURDIR}/../../net/tcl-scotty/patches

do-install:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} tki-install
	${INSTALL_DATA} ${WRKSRC}/../doc/tkined.1 ${PREFIX}/man/man1

post-install:
	cd ${PREFIX}/bin && ${LN} -f -s tkined1.4.11 tkined

.include "../../mk/bsd.pkg.mk"
