# $NetBSD: Makefile,v 1.3 2001/05/05 19:51:18 jlam Exp $
#

DISTNAME=	scotty-2.1.10
PKGNAME=	tkined-1.4.10
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://wwwhome.cs.utwente.nl/~schoenw/scotty/
COMMENT=	graphical network discovery and monitoring tool based on scotty

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	tcl-scotty-2.1.10:../../net/tcl-scotty

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --with-tcl-config=${PREFIX}/lib --enable-multicast \
		--enable-gdmo --with-tk-config=${PREFIX}/lib
CONFIGURE_ENV+=	TARGET=tkined

USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/unix

FILESDIR=	${.CURDIR}/../../net/tcl-scotty/files
PATCHDIR=	${.CURDIR}/../../net/tcl-scotty/patches

do-install:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} tki-install
	${INSTALL_DATA} ${WRKSRC}/../doc/tkined.1 ${PREFIX}/man/man1

post-install:
	cd ${PREFIX}/bin && ${LN} -f -s tkined1.4.10 tkined

.include "../../mk/bsd.pkg.mk"
