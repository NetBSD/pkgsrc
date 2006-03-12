# $NetBSD: Makefile,v 1.13 2006/03/12 15:00:55 rillig Exp $
#

DISTNAME=	hobbit-4.0-beta6
PKGNAME=	hobbit-4.0b6
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hobbitmon/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://hobbitmon.sourceforge.net/
COMMENT=	Network services monitor a la Big Brother

DEPENDS+=	fping>2:../../net/fping

HAS_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

BBUSER?=	hobbit
BBGROUP?=	hobbit
BBTOPDIR?=	${PREFIX}/hobbit
BBLOGDIR?=	${VARBASE}/log/hobbit
BBHOSTURL?=	/hobbit
CGIDIR?=	${BBTOPDIR}/cgi-bin
BBCGIURL?=	/cgi-bin
BBHOSTIP?=	127.0.0.1

PKG_GROUPS=	${BBGROUP}
PKG_USERS=	${BBUSER:Q}:${BBGROUP:Q}::Hobbit\ monitor:${BBTOPDIR:Q}

CONFIGURE_ENV+=	TARGET=hobbit
CONFIGURE_ENV+=	FPING=${PREFIX:Q}/sbin/fping
CONFIGURE_ENV+=	RRDINC=${PREFIX:Q}/include
CONFIGURE_ENV+=	RRDLIB=${PREFIX:Q}/lib/librrd.a
CONFIGURE_ENV+=	PNGLIB=${PREFIX:Q}/lib/libpng.a
CONFIGURE_ENV+=	LDAPINC=${PREFIX:Q}/include
CONFIGURE_ENV+=	LDAPLIB=${PREFIX:Q}/lib
CONFIGURE_ENV+=	OSSLINC=${PREFIX:Q}/include
CONFIGURE_ENV+=	OSSLLIB=${PREFIX:Q}/lib
CONFIGURE_ENV+=	PCREINC=${PREFIX:Q}/include
CONFIGURE_ENV+=	PCRELIB=${PREFIX:Q}/lib
CONFIGURE_ENV+=	ENABLESSL=y
CONFIGURE_ENV+=	ENABLELDAP=y
CONFIGURE_ENV+=	ENABLELDAPSSL=y
CONFIGURE_ENV+=	BBHOSTNAME=""
CONFIGURE_ENV+=	BBUSER=${BBUSER:Q}
CONFIGURE_ENV+=	BBTOPDIR=${BBTOPDIR:Q}
CONFIGURE_ENV+=	BBHOSTURL=${BBHOSTURL:Q}
CONFIGURE_ENV+=	CGIDIR=${CGIDIR:Q}
CONFIGURE_ENV+=	BBCGIURL=${BBCGIURL:Q}
CONFIGURE_ENV+=	HTTPDGID=${APACHE_GROUP:Q}
CONFIGURE_ENV+=	BBLOGDIR=${BBLOGDIR:Q}
CONFIGURE_ENV+=	BBHOSTIP=${BBHOSTIP:Q}
CONFIGURE_ENV+=	MANROOT=${PREFIX:Q}/man
CONFIGURE_ENV+=	BARS=all
CONFIGURE_ENV+=	USENEWHIST=y
CONFIGURE_ENV+=	PIXELCOUNT=560

MAKE_ENV+=	MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=	PKGDIR=${PREFIX:Q}

do-install:
	set -e;							\
	cd ${WRKSRC:Q};						\
	if ${TEST} -f ${BBTOPDIR:Q}/server/etc/bb-hosts ; then	\
		${GMAKE} install ;				\
	else							\
		${GMAKE} setup ;				\
	fi

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
