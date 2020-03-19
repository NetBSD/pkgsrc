# $NetBSD: Makefile,v 1.39 2020/03/19 14:03:29 wiz Exp $

DISTNAME=	Mailer-0.2.0
PKGNAME=	deforaos-mailer-0.2.0
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Mailer/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop e-mail client
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

CONFLICTS=	john-[0-9]*

LDFLAGS.SunOS+=	-lnsl -lsocket

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/compose.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/compose.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/mailer.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/mailer.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/compose.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/compose.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/mailer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mailer.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
