# $NetBSD: Makefile,v 1.28 2026/08/03 13:12:27 wiz Exp $

DISTNAME=	kinput2-v3.1
PKGNAME=	kinput2-3.1
PKGREVISION=	5
CATEGORIES=	inputmethod japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/

PATCH_SITES=		http://canna.osdn.jp/canna37patches/
PATCHFILES=		kinput2-v3.1-canna37.diff

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Input server of Japanese text

MAKE_JOBS_SAFE=	NO
USE_IMAKE=	YES

PLIST_SRC=	${PKGDIR}/PLIST.common

.include "options.mk"

MAKE_ENV+=	PORT_IMAKE_DEFINES=${KINPUT2_DEFS:Q}

pre-configure:
	${MV} -f ${WRKSRC}/Kinput2.conf ${WRKSRC}/Kinput2.conf.org
	${CP} ${FILESDIR}/Kinput2.conf ${WRKSRC}/Kinput2.conf

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
