# $NetBSD: Makefile,v 1.8 2004/04/19 21:43:21 xtraeme Exp $
# FreeBSD Id: Makefile,v 1.4 1999/06/06 13:19:49 taoka Exp $

DISTNAME=	kinput2-v3
PKGNAME=	kinput2-3.0
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Input server of Japanese text

USE_BUILDLINK3=	YES
USE_IMAKE=	YES

PLIST_SRC=	${PKGDIR}/PLIST-common

.include "../../mk/bsd.prefs.mk"
.if defined(USE_CANNA) && ${USE_CANNA} != YES &&	\
    defined(USE_WNN4) && ${USE_WNN4} != YES &&		\
    defined(USE_WNN6) && ${USE_WNN6} != YES &&		\
    defined(USE_SJ3) && ${USE_SJ3} != YES
PKG_FAIL_REASON= ${PKGNAME} is ignored. because USE_CANNA,USE_WNN4,USE_WNN6,USE_SJ3 are "NO"
.endif

.if !defined(USE_CANNA) || ${USE_CANNA} == YES
.include "../../inputmethod/canna-lib/buildlink3.mk"
KINPUT2_DEF+=	-DUseCanna -Dport_CANNASRC=${BUILDLINK_PREFIX.canna}/include \
		-Dport_CANNALIB="${LDFLAGS} -lcanna16"
.endif

#.if defined(USE_WNN6) && ${USE_WNN6} == YES
#DEPENDS+=
#KINPUT2_DEF+=	-DUseWnn -DUseWnn6 -Dport_WNNINCDIR=${LOCALBASE}/include/wnn \
#		-Dport_WNNLIB="${LDFLAGS} -lwnn6 -lcrypt"
#.elif (!defined(USE_WNN4) || ${USE_WNN4} == YES)
.if !defined(USE_WNN4) || ${USE_WNN4} == YES
.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
KINPUT2_DEF+=	-DUseWnn -Dport_WNNINCDIR=${BUILDLINK_PREFIX.ja-freewnn}/include/wnn \
		-Dport_WNNLIB="${LDFLAGS} -lwnn -lcrypt"
PLIST_SRC+=	${PKGDIR}/PLIST-freewnn
.endif

.if !defined(USE_SJ3) || ${USE_SJ3} == YES
.include "../../inputmethod/sj3-lib/buildlink3.mk"
KINPUT2_DEF+=	-DUseSj3 -Dport_SJ3SRC=${BUILDLINK_PREFIX.sj3}/include \
		-Dport_SJ3LIB="${LDFLAGS} -lsj3lib"
PLIST_SRC+=	${PKGDIR}/PLIST-sj3
.endif

MAKE_ENV+=	PORT_IMAKE_DEFINES='${KINPUT2_DEF}'

pre-configure:
	${MV} -f ${WRKSRC}/Kinput2.conf ${WRKSRC}/Kinput2.conf.org
	${CP} ${FILESDIR}/Kinput2.conf ${WRKSRC}/Kinput2.conf

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

.include "../../mk/bsd.pkg.mk"
