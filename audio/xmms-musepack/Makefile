# $NetBSD: Makefile,v 1.2 2004/03/12 02:57:37 snj Exp $
#

DISTNAME=	xmms-musepack-0.94
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpegplus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/mpegplus/
COMMENT=	Musepack audio output plugin for XMMS

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

CFLAGS+=	-DVERSION='"${PKGVERSION}"'
XMMS_CONFIG=	${BUILDLINK_PREFIX.xmms}/bin/xmms-config

do-build:
	cd ${WRKSRC} && for f in *.c; do \
		${SHLIBTOOL} --mode=compile ${CC} ${CFLAGS} \
		`${XMMS_CONFIG} --cflags` -c $$f || break; \
	done
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=link ${CC} ${LDFLAGS} \
		-o libmusepack.la *.lo `${XMMS_CONFIG} --libs` \
		-rpath ${PREFIX}/lib/xmms/Input \
		-module -avoid-version

do-install:
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=install \
		${INSTALL_DATA} libmusepack.la ${PREFIX}/lib/xmms/Input

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
