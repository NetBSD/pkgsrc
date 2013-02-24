# $NetBSD: Makefile,v 1.2 2013/02/24 15:59:12 khorben Exp $
#

DISTNAME=	Terminal-0.0.0
PKGNAME=	deforaos-terminal-0.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.defora.org/os/download/download/4281/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop terminal emulator

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

CONFLICTS=	xfce4-terminal-[0-9]*

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/terminal.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/terminal.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
