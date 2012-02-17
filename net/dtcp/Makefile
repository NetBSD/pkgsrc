# $NetBSD: Makefile,v 1.23 2012/02/17 14:09:05 hans Exp $
#

DISTNAME=	dtcp-20060109
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	qpopper-[0-9]*:../../mail/qpopper

RCD_SCRIPTS=	dtcpc dtcps

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX} DESTDIR=${DESTDIR}

USE_BSD_MAKEFILE=	yes

.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
