# $NetBSD: Makefile,v 1.3 2005/02/20 10:51:32 manu Exp $
#

DISTNAME=	hobbit-4.0-beta6
PKGNAME=	hobbit-4.0b6
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hobbitmon/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://hobbitmon.sourceforge.net/
COMMENT=	Network services monitor a la Big Brother

DEPENDS+=	fping>2:../../net/fping

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=YES

.include "../../mk/bsd.prefs.mk"

BBUSER?=	hobbit
BBGROUP?=	hobbit
BBTOPDIR?=	${PREFIX}/hobbit
BBLOGDIR?=	/var/log/hobbit
BBHOSTURL?=	/hobbit
CGIDIR?=	${BBTOPDIR}/cgi-bin
BBCGIURL?=	/cgi-bin
BBHOSTIP?=	127.0.0.1

PKG_GROUPS=	${BBGROUP}
PKG_USERS=	${BBUSER}:${BBGROUP}::Hobbit\\ monitor:${BBTOPDIR}

CONFIGURE_ENV+=	TARGET=hobbit
CONFIGURE_ENV+=	FPING=${PREFIX}/sbin/fping
CONFIGURE_ENV+=	RRDINC=${PREFIX}/include
CONFIGURE_ENV+=	RRDLIB=${PREFIX}/lib/librrd.a
CONFIGURE_ENV+=	PNGLIB=${PREFIX}/lib/libpng.a
CONFIGURE_ENV+=	LDAPINC=${PREFIX}/include
CONFIGURE_ENV+=	LDAPLIB=${PREFIX}/lib
CONFIGURE_ENV+=	OSSLINC=${PREFIX}/include
CONFIGURE_ENV+=	OSSLLIB=${PREFIX}/lib
CONFIGURE_ENV+=	PCREINC=${PREFIX}/include
CONFIGURE_ENV+=	PCRELIB=${PREFIX}/lib
CONFIGURE_ENV+=	ENABLESSL=y
CONFIGURE_ENV+=	ENABLELDAP=y
CONFIGURE_ENV+=	ENABLELDAPSSL=y
CONFIGURE_ENV+=	BBHOSTNAME=""
CONFIGURE_ENV+=	BBUSER=${BBUSER}
CONFIGURE_ENV+=	BBTOPDIR=${BBTOPDIR}
CONFIGURE_ENV+=	BBHOSTURL=${BBHOSTURL}
CONFIGURE_ENV+=	CGIDIR=${CGIDIR}
CONFIGURE_ENV+=	BBCGIURL=${BBCGIURL}
CONFIGURE_ENV+=	HTTPDGID=${APACHE_GROUP}
CONFIGURE_ENV+=	BBLOGDIR=${BBLOGDIR}
CONFIGURE_ENV+=	BBHOSTIP=${BBHOSTIP}
CONFIGURE_ENV+=	MANROOT=${PREFIX}/man
CONFIGURE_ENV+=	BARS=all
CONFIGURE_ENV+=	USENEWHIST=y
CONFIGURE_ENV+=	PIXELCOUNT=560

MAKE_ENV+=	MAKE=${MAKE_PROGRAM}
MAKE_ENV+=	PKGDIR=${PREFIX}

do-install:
	cd ${WRKSRC} ; 						\
	if ${TEST} -f ${BBTOPDIR}/server/etc/bb-hosts ; then	\
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
