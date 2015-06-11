# $NetBSD: Makefile,v 1.13 2015/06/11 18:47:33 khorben Exp $

DISTNAME=	Editor-0.3.1
PKGNAME=	deforaos-editor-0.3.1
CATEGORIES=	editors
MASTER_SITES=	http://www.defora.org/os/download/download/4356/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop text editor

LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/editor.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/editor.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/filter.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/filter.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/editor.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/editor.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/filter.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/filter.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
