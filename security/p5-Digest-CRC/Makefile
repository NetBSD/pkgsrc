# $NetBSD: Makefile,v 1.1.1.1 2005/01/11 16:48:38 tv Exp $
#

DISTNAME=	Digest-CRC-0.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5crc
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-CRC/
COMMENT=	Perl5 extension interface for cyclic redundancy check algorithms

DEPENDS+=	p5-Digest>=1.00:../p5-Digest

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/CRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
