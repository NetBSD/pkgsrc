# $NetBSD: Makefile,v 1.5 2004/11/28 04:10:36 taca Exp $
#

DISTNAME=	dtcp-20040611
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	${RUBY_PKGPREFIX}-digest-*:../../security/ruby-digest
DEPENDS+=	qpopper-*:../../mail/qpopper

MAKE_ENV+=	RUBY=${RUBY}
RCD_SCRIPTS=	dtcpc dtcps
CONF_DEPENDS=	YES

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
