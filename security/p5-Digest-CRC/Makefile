# $NetBSD: Makefile,v 1.33 2020/08/31 18:11:16 wiz Exp $

DISTNAME=	Digest-CRC-0.22.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/O/OL/OLIMAUL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-CRC
COMMENT=	Perl5 extension interface for cyclic redundancy check algorithms
LICENSE=	public-domain

PERL5_PACKLIST=	auto/Digest/CRC/.packlist
WRKSRC=		${WRKDIR}/Digest-CRC-0.22

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
