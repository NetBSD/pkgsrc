# $NetBSD: Makefile,v 1.15 2003/09/28 21:08:59 sjg Exp $
#

DISTNAME=       bmake-20030928
WRKSRC=		${WRKDIR}/bmake
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.NetBSD.org/pub/incoming/sjg/

MAINTAINER=	sjg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

DEPENDS+=	mk-files>=20030714:../../devel/mk-files

ONLY_FOR_PLATFORM=	NetBSD-*-*

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
