# $NetBSD: Makefile,v 1.8 2014/05/05 00:47:43 ryoon Exp $

DISTNAME=	Coder-0.0.0
PKGNAME=	deforaos-coder-0.0.0
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4288/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS Coder

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/coder.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/coder.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/sequel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sequel.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/simulator.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/simulator.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "../../databases/deforaos-libdatabase/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
