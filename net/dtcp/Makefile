# $NetBSD: Makefile,v 1.35 2024/02/10 14:42:39 taca Exp $
#

DISTNAME=	dtcp-20130602
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	https://www.mahoroba.org/~ume/ipv6/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
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
