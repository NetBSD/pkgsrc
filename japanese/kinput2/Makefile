# $NetBSD: Makefile,v 1.4 1999/09/03 04:11:07 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.4 1999/06/06 13:19:49 taoka Exp $

DISTNAME=	kinput2-v3
PKGNAME=	kinput2-3.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"
.if defined(USE_CANNA) && ${USE_CANNA} != YES &&	\
    defined(USE_WNN4) && ${USE_WNN4} != YES &&		\
    defined(USE_WNN6) && ${USE_WNN6} != YES &&		\
    defined(USE_SJ3) && ${USE_SJ3} != YES
IGNORE=	"is ignored. because USE_CANNA,USE_WNN4,USE_WNN6,USE_SJ3 are \"NO\""
.endif

.if !defined(USE_CANNA) || ${USE_CANNA} == YES
DEPENDS+=	Canna-lib-3.5b2:../../japanese/canna-lib
KINPUT2_DEF+=	-DUseCanna -Dport_CANNASRC=${LOCALBASE}/include/canna \
		-Dport_CANNALIB="${LDFLAGS} -lcanna16"
.endif

#.if defined(USE_WNN6) && ${USE_WNN6} == YES
#DEPENDS+=
#KINPUT2_DEF+=	-DUseWnn -DUseWnn6 -Dport_WNNINCDIR=$(LOCALBASE)/include/wnn \
#		-Dport_WNNLIB="${LDFLAGS} -lwnn6 -lcrypt"
#.elif (!defined(USE_WNN4) || ${USE_WNN4} == YES)
.if !defined(USE_WNN4) || ${USE_WNN4} == YES
DEPENDS+=	ja-FreeWnn-lib-1.10:../../japanese/freewnn-lib
KINPUT2_DEF+=	-DUseWnn -Dport_WNNINCDIR=${LOCALBASE}/include/wnn \
		-Dport_WNNLIB="${LDFLAGS} -lwnn -lcrypt"
.endif

.if !defined(USE_SJ3) || ${USE_SJ3} == YES
DEPENDS+=	sj3-lib-2.0.1.20:../../japanese/sj3-lib
KINPUT2_DEF+=	-DUseSj3 -Dport_SJ3SRC=${LOCALBASE}/include \
		-Dport_SJ3LIB="${LDFLAGS} -lsj3lib"
.endif

MAKE_ENV+=	PORT_IMAKE_DEFINES='${KINPUT2_DEF}'

pre-configure:
	${MV} -f ${WRKSRC}/Kinput2.conf ${WRKSRC}/Kinput2.conf.org
	${CP} ${FILESDIR}/Kinput2.conf ${WRKSRC}/Kinput2.conf

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

.include "../../mk/bsd.pkg.mk"
