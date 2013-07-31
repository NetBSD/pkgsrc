# $NetBSD: Makefile,v 1.8 2013/07/31 10:23:17 he Exp $
#

VERSION=	20130404
DISTNAME=	20130404
PKGREVISION=	1
PKGNAME=	fpdns-0.10.0pre${VERSION}
CATEGORIES=	net
MASTER_SITES=	https://github.com/kirei/fpdns/archive/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kirei/fpdns/
COMMENT=	Fingerprinting DNS servers
LICENSE=	modified-bsd

DEPENDS+=	p5-Net-DNS>=0.42:../../net/p5-Net-DNS

WRKSRC=		${WRKDIR}/fpdns-${VERSION}
REPLACE_PERL=	apps/fpdns
USE_TOOLS+=	perl
USE_LANGUAGES=	# none

PERL5_CONFIGURE=	yes
PERL5_PACKLIST=		auto/Net/DNS/Fingerprint/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
