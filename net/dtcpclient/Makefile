# $NetBSD: Makefile,v 1.15 2010/03/08 11:47:19 obache Exp $
#

DISTNAME=	dtcpclient-20060526
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol client

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-* Darwin-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

RCD_SCRIPTS=	dtcpclient

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	dtcpclient.8 dtcpclient.script dtcpclient.c
SUBST_SED.paths=	-e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'
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
