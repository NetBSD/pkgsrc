# $NetBSD: Makefile,v 1.11 2005/03/06 17:11:58 taca Exp $
#

DISTNAME=	dtcp-20040611
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	qpopper-[0-9]*:../../mail/qpopper

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == "16"
DEPENDS+=	${RUBY_PKGPREFIX}-digest-[0-9]*:../../security/ruby${RUBY_VER}-digest
.else
DEPENDS+=	${RUBY_PKGPREFIX}-digest-[0-9]*:../../security/ruby-digest
.endif
DEPENDS+=	${RUBY_PKGPREFIX}-dbm-[0-9]*:../../databases/ruby-dbm

MAKE_ENV+=	RUBY=${RUBY}
RCD_SCRIPTS=	dtcpc dtcps
USE_PKGINSTALL=	YES
FILES_SUBST+=	RUBY=${RUBY}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
