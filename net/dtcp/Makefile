# $NetBSD: Makefile,v 1.10 2005/02/21 15:39:42 taca Exp $
#

DISTNAME=	dtcp-20040611
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	qpopper-*:../../mail/qpopper

MAKE_ENV+=	RUBY=${RUBY}
RCD_SCRIPTS=	dtcpc dtcps
USE_PKGINSTALL=	YES

FILES_SUBST+=	RUBY=${RUBY}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
