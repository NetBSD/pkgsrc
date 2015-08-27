# $NetBSD: Makefile,v 1.11 2015/08/27 22:31:48 khorben Exp $

DISTNAME=	Mixer-0.1.2
PKGNAME=	deforaos-mixer-0.1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.defora.org/os/download/download/4369/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop volume mixer

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/mixer.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/mixer.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/mixer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mixer.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
