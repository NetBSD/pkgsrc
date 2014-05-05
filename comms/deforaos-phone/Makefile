# $NetBSD: Makefile,v 1.16 2014/05/05 00:47:41 ryoon Exp $
#

DISTNAME=	Phone-0.3.12
PKGNAME=	deforaos-phone-0.3.12
PKGREVISION=	8
CATEGORIES=	comms net
MASTER_SITES=	http://www.defora.org/os/download/download/4296/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop telephony

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/phone.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/phone.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/phonectl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/phonectl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/sofia-sip/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/deforaos-locker/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
