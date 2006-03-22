# $NetBSD: Makefile,v 1.6 2006/03/22 22:50:33 tv Exp $
#

DISTNAME=	Digest-CRC-0.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5crc
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	tv@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-CRC/
COMMENT=	Perl5 extension interface for cyclic redundancy check algorithms

DEPENDS+=	p5-Digest>=1.00:../../security/p5-Digest

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Digest/CRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
