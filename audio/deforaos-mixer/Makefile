# $NetBSD: Makefile,v 1.25 2020/03/08 16:48:38 wiz Exp $

DISTNAME=	Mixer-0.4.0
PKGNAME=	deforaos-mixer-0.4.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Mixer/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop volume mixer

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
