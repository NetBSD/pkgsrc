# $NetBSD: Makefile,v 1.30 2016/03/13 09:36:58 taca Exp $
#

DISTNAME=	dtcp-20130602
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.mahoroba.org/~ume/ipv6/
MASTER_SITES+=	http://home.jp.FreeBSD.org/~ume/ipv6/
MASTER_SITES+=	http://www.imasy.or.jp/~ume/ipv6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client
LICENSE=	modified-bsd

DEPENDS+=	qpopper-[0-9]*:../../mail/qpopper

RCD_SCRIPTS=	dtcpc dtcps

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX} DESTDIR=${DESTDIR}

USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff

.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
