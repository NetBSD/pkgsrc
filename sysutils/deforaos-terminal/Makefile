# $NetBSD: Makefile,v 1.29 2022/08/11 05:09:14 gutteridge Exp $
#

DISTNAME=	Terminal-0.2.0
PKGNAME=	deforaos-terminal-0.2.0
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Terminal/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop terminal emulator

LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

DEPENDS+=	{xterm,mxterm}-[0-9]*:../../x11/xterm

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/terminal.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/terminal.html
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/terminal.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/terminal.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
