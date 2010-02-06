# $NetBSD: Makefile,v 1.26 2010/02/06 13:58:06 spz Exp $
#

DISTNAME=	hobbit-4.0-beta6
PKGNAME=	hobbit-4.0b6
PKGREVISION=	13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hobbitmon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hobbitmon.sourceforge.net/
COMMENT=	Network services monitor a la Big Brother

DEPENDS+=	fping>2:../../net/fping

HAS_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run
REPLACE_PERL+=	hobbitd/maint.pl.DIST
INSTALL_TARGET=	setup

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
PKG_USERS=	${BBUSER:Q}:${BBGROUP:Q}

PKG_GECOS.${BBUSER}=	Hobbit monitor
PKG_HOME.${BBUSER}=	${BBTOPDIR}

PKG_GROUPS_VARS+=	BBGROUP
PKG_USERS_VARS+=	BBUSER

EVAL_PREFIX+=	PREFIX.fping=fping

CONFIGURE_ENV+=	TARGET=hobbit
CONFIGURE_ENV+=	FPING=${PREFIX.fping}/sbin/fping
CONFIGURE_ENV+=	RRDINC=${BUILDLINK_PREFIX.rrdtool}/include
CONFIGURE_ENV+=	RRDLIB=${BUILDLINK_PREFIX.rrdtool}/lib/librrd.a
CONFIGURE_ENV+=	PNGLIB=${BUILDLINK_PREFIX.png}/lib/libpng.a
CONFIGURE_ENV+=	LDAPINC=${BUILDLINK_PREFIX.openldap-client}/include
CONFIGURE_ENV+=	LDAPLIB=${BUILDLINK_PREFIX.openldap-client}/lib
CONFIGURE_ENV+=	OSSLINC=${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ENV+=	OSSLLIB=${BUILDLINK_PREFIX.openssl}/lib
CONFIGURE_ENV+=	PCREINC=${BUILDLINK_PREFIX.pcre}/include
CONFIGURE_ENV+=	PCRELIB=${BUILDLINK_PREFIX.pcre}/lib
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
CONFIGURE_ENV+=	MANROOT=${PREFIX}/${PKGMANDIR}/
CONFIGURE_ENV+=	BARS=all
CONFIGURE_ENV+=	USENEWHIST=y
CONFIGURE_ENV+=	PIXELCOUNT=560

MAKE_ENV+=	MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=	PKGDIR=${PREFIX:Q}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/apache.mk"

.include "../../mk/bsd.pkg.mk"
