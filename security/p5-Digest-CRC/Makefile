# $NetBSD: Makefile,v 1.34 2020/09/08 13:16:43 wiz Exp $

DISTNAME=	Digest-CRC-0.22.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OL/OLIMAUL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-CRC
COMMENT=	Perl5 extension interface for cyclic redundancy check algorithms
LICENSE=	public-domain

PERL5_PACKLIST=	auto/Digest/CRC/.packlist
WRKSRC=		${WRKDIR}/Digest-CRC-0.22

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
