# $NetBSD: Makefile,v 1.2 2005/02/20 04:43:26 hamajima Exp $
#

DISTNAME=	dtcpclient-20040923
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol client

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

RCD_SCRIPTS=	dtcpclient
USE_PKGINSTALL=	YES

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	dtcpclient.8
SUBST_SED.paths=	's|/usr/local|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
