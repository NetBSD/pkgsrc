# $NetBSD: Makefile,v 1.7 2005/01/23 05:01:44 hamajima Exp $
#

DISTNAME=	dtcp-20040611
PKGREVISION=	1
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
USE_PKGINSTALL=	YES

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
