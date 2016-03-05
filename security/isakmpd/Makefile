# $NetBSD: Makefile,v 1.51 2016/03/05 11:29:21 jperkin Exp $
#

DISTNAME=		isakmpd-20030903
PKGREVISION=		10
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenBSD IKE daemon

# Dragonfly upstream says to use security/racoon2 instead.
NOT_FOR_PLATFORM=	DragonFly-*-*

MAKE_JOBS_SAFE=		no

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
PKG_FAIL_REASON+=	"${PKGNAME} requires ipsec-ready ${OPSYS}"
.endif

WRKSRC=			${WRKDIR}/isakmpd

BUILD_TARGET=		depend all

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/${PKGMANDIR}

PKG_SYSCONFSUBDIR=	isakmpd

RCD_SCRIPTS=		isakmpd
RCD_SCRIPT_WRK.isakmpd=	${WRKDIR}/isakmpd.sh

SUBST_CLASSES+=		ssl
SUBST_STAGE.ssl=	pre-configure
SUBST_MESSAGE.ssl=	Fixing references to buildlink directories
SUBST_FILES.ssl=	sysdep/netbsd/Makefile.sysdep
SUBST_VARS.ssl=		BUILDLINK_PREFIX.openssl

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-configure
SUBST_MESSAGE.cfg=	Fixing references to configuration directory
SUBST_FILES.cfg=	conf.h policy.h ike_auth.h
SUBST_SED.cfg=		-e "s+/etc/isakmpd+${PKG_SYSCONFDIR}+g"

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing manual page references
SUBST_FILES.man=	isakmpd.8 isakmpd.conf.5 isakmpd.policy.5
SUBST_SED.man=		-e "s+/usr/share/ipsec+${PREFIX}/share/examples+g"
SUBST_SED.man+=		-e "s+/etc/isakmpd+${PKG_SYSCONFDIR}+g"

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_MESSAGE.destdir=	Fixing ownership for DESTDIR installations
SUBST_FILES.destdir=	Makefile apps/certpatch/Makefile
SUBST_VARS.destdir=	BINOWN BINGRP MANOWN MANGRP

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/cat5
INSTALLATION_DIRS+=	${PKGMANDIR}/man8 ${PKGMANDIR}/cat8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
