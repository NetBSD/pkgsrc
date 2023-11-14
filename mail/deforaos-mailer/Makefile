# $NetBSD: Makefile,v 1.51 2023/11/14 14:02:24 wiz Exp $

DISTNAME=	Mailer-0.2.0
PKGNAME=	deforaos-mailer-0.2.0
PKGREVISION=	15
CATEGORIES=	mail
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Mailer/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop e-mail client
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

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
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
