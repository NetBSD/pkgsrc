# $NetBSD: Makefile,v 1.3 2004/06/23 04:58:21 hamajima Exp $
#

DISTNAME=	dtcp-20030228
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	ruby-digest-*:../../security/ruby-digest
DEPENDS+=	qpopper-*:../../mail/qpopper

RCD_SCRIPTS=	dtcpc dtcps
CONF_DEPENDS=	YES

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	dtcpauth.8 dtcpc.8 dtcps.8
SUBST_SED.paths=	's|/usr/local|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
