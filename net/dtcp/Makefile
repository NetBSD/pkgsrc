# $NetBSD: Makefile,v 1.18 2006/07/09 13:21:02 taca Exp $
#

DISTNAME=	dtcp-20060109
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	qpopper-[0-9]*:../../mail/qpopper

RCD_SCRIPTS=	dtcpc dtcps

MAKE_ENV+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
