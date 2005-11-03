# $NetBSD: Makefile,v 1.15 2005/11/03 07:20:56 taca Exp $
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

RCD_SCRIPTS=	dtcpc dtcps
USE_PKGINSTALL=	YES

.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
