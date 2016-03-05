# $NetBSD: Makefile,v 1.24 2016/03/05 11:29:03 jperkin Exp $
#

DISTNAME=	dtcpclient-20090812
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol client
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes

RCD_SCRIPTS=	dtcpclient

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	dtcpclient.8 dtcpclient.script dtcpclient.c
SUBST_SED.paths=	-e 's|/usr/local/etc/dtcpclient.script|${PREFIX}/sbin/dtcpclient-script|'
SUBST_SED.paths+=	-e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|/usr/local|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|/var|${VARBASE}|g'

MAKE_ENV+=	VARBASE=${VARBASE}

BUILD_DEFS+=	VARBASE

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.prefs.mk"

# Keep this in sync with patch-aa, as that determines whether -lcrypto
# is used and if we get it wrong we'll get a silent dependency on
# builtin openssl on platforms where that exists, which isn't good.
.if ${OPSYS} != "NetBSD" || ${OPSYS} != "OpenBSD" || \
    ${OPSYS} != "FreeBSD" || ${OPSYS} != "DragonFly"
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
