# $NetBSD: Makefile,v 1.1.1.1 2001/05/25 12:41:14 agc Exp $
#

DISTNAME=       bmake-3.1.6
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.netbsd.org/pub/incoming/sjg/

MAINTAINER=	sjg@netbsd.org
HOMEPAGE=	http://www.quick.com.au/help/sjg/bmake.html
COMMENT=	NetBSD version of 'make' utility

DEPENDS+=	mk-files-1.2.2:../../devel/mk-files

WRKSRC=		${WRKDIR}/bmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	  						\
	--with-default-sys-path=${PREFIX}/share/mk:/usr/share/mk:/usr/local/share/mk:/opt/share/mk

do-build:
	cd ${WRKSRC}; make -f makefile.boot bootstrap; ./bmake -f Makefile; ./bmake -f Makefile bmake.1

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/bmake ${PREFIX}/bin
	${BSD_INSTALL_MAN} ${WRKSRC}/bmake.cat1 ${PREFIX}/man/cat1/bmake.0
	${BSD_INSTALL_MAN} ${WRKSRC}/bmake.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
