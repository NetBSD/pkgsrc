# $NetBSD: Makefile,v 1.22 2015/07/12 05:31:47 dholland Exp $
#

DISTNAME=	dtcpclient-20090812
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
.if ${OPSYS} == "Darwin"
.include "../../security/openssl/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
