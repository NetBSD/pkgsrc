# $NetBSD: Makefile,v 1.5 2002/09/20 07:00:52 sjg Exp $
#

DISTNAME=       bmake-3.1.13
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.netbsd.org/pub/incoming/sjg/

MAINTAINER=	sjg@netbsd.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

DEPENDS+=	mk-files>=1.3.2:../../devel/mk-files

WRKSRC=		${WRKDIR}/bmake

makesyspath=${PREFIX}/share/mk:/usr/share/mk:/usr/local/share/mk:/opt/share/mk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-default-sys-path=${makesyspath}

do-build:
	cd ${WRKSRC} && MAKESYSPATH=${makesyspath} make -f makefile.boot bootstrap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bmake.cat1 ${PREFIX}/man/cat1/bmake.0
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
