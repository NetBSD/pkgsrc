# $NetBSD: Makefile,v 1.1.1.1 2000/04/04 03:01:11 itojun Exp $
#

DISTNAME=	racoon-0.0
CATEGORIES=	security net

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http:/www.kame.net/

# openssl is necessary for RSA libraries
DEPENDS+=	openssl-0.9.4:../../security/openssl

CONFLICTS+=	racoon-*

# crypto-intl configuration.  needs "cvs login".
ANONCVS=	:pserver:anoncvs@anoncvs.jp.netbsd.org:/cvs/cvsroot
INTL=		intl
# crypto-us configuration.  needs "CVS_RSH = ssh".  not tested.
#ANONCVS=	anoncvs@anoncvs.netbsd.org:/cvsroot
#INTL=		us

WRKSRC=		${WRKDIR}/racoon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-debug
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

do-fetch::

do-extract:
	${MKDIR} ${WRKDIR}
	(cd ${WRKDIR}; cvs -d ${ANONCVS} co -P -d racoon \
		cryptosrc-${INTL}/crypto-${INTL}/dist/kame/racoon)
	(cd ${WRKDIR}; cvs -d ${ANONCVS} co -P -d libpfkey \
		cryptosrc-${INTL}/crypto-${INTL}/dist/kame/libpfkey)
	${CP} ${FILESDIR}/Makefile.libpfkey ${WRKDIR}/libpfkey/Makefile

pre-build:
	(cd ${WRKDIR}/libpfkey; make)

.include "../../mk/bsd.pkg.mk"
