# $NetBSD: Makefile,v 1.35 2021/05/24 19:54:02 wiz Exp $

DISTNAME=	Digest-CRC-0.22.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
