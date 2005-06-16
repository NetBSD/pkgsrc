# $NetBSD: Makefile,v 1.22 2005/06/16 06:57:45 jlam Exp $
#

DISTNAME=       bmake-20050530
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/

MAINTAINER=	sjg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

DEPENDS+=	mk-files>=20030714:../../devel/mk-files

WRKSRC=		${WRKDIR}/bmake

makesyspath=${PREFIX}/share/mk:/usr/share/mk:/usr/local/share/mk:/opt/share/mk
GNU_CONFIGURE=	no
CONFIGURE_ARGS+= --with-default-sys-path=${makesyspath}

INSTALLATION_DIRS=	bin man/cat1 man/man1

do-configure:

do-build:
	cd ${WRKDIR} && ./bmake/boot-strap -q -o ${OPSYS} ${CONFIGURE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${OPSYS}/bmake.cat1 ${PREFIX}/man/cat1/bmake.0
	${INSTALL_MAN} ${WRKDIR}/${OPSYS}/bmake.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
