# $NetBSD: Makefile,v 1.9 2005/02/01 14:26:14 hamajima Exp $
#

DISTNAME=	dtcp-20040611
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	${RUBY_PKGPREFIX}-digest-*:../../security/ruby-digest
DEPENDS+=	${RUBY_PKGPREFIX}-dbm-*:../../databases/ruby-dbm
DEPENDS+=	qpopper-*:../../mail/qpopper

MAKE_ENV+=	RUBY=${RUBY}
RCD_SCRIPTS=	dtcpc dtcps
USE_PKGINSTALL=	YES

FILES_SUBST+=	RUBY=${RUBY}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
