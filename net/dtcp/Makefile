# $NetBSD: Makefile,v 1.1.1.1 2004/06/05 07:43:25 hamajima Exp $
#

DISTNAME=	dtcp-20030228
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

.include "../../mk/bsd.pkg.mk"
