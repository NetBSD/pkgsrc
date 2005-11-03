# $NetBSD: Makefile,v 1.14 2005/11/03 05:15:09 taca Exp $
#

DISTNAME=	dtcp-20050521
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	qpopper-[0-9]*:../../mail/qpopper

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == "16"
DEPENDS+=	${RUBY_PKGPREFIX}-dbm-[0-9]*:../../databases/ruby-dbm
DEPENDS+=	${RUBY_PKGPREFIX}-digest-[0-9]*:../../security/ruby${RUBY_VER}-digest
.endif

RCD_SCRIPTS=	dtcpc dtcps
USE_PKGINSTALL=	YES

.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
