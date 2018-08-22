# $NetBSD: Makefile,v 1.19 2018/08/22 09:46:21 wiz Exp $

DISTNAME=		Crypt-ECB-2.21
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
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
