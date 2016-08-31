# $NetBSD: Makefile,v 1.16 2016/08/31 06:05:00 wiz Exp $

DISTNAME=		Crypt-ECB-2.20
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-ECB/
COMMENT=		Perl5 Electronic Codebook mode for various crypto algorithms
LICENSE=		gnu-gpl-v1 OR artistic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/ECB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
