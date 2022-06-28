# $NetBSD: Makefile,v 1.18 2022/06/28 11:34:59 wiz Exp $

VERSION=	20190131
DISTNAME=	20190131
PKGNAME=	fpdns-0.10.0pre${VERSION}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://github.com/kirei/fpdns/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kirei/fpdns/
COMMENT=	Fingerprinting DNS servers
LICENSE=	modified-bsd

DEPENDS+=	p5-Net-DNS>=0.42:../../net/p5-Net-DNS

WRKSRC=		${WRKDIR}/fpdns-${VERSION}
REPLACE_PERL=	apps/fpdns
USE_TOOLS+=	perl
USE_LANGUAGES=	# none

PERL5_PACKLIST=		auto/Net/DNS/Fingerprint/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
