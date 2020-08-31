# $NetBSD: Makefile,v 1.25 2020/08/31 18:11:11 wiz Exp $
#

DISTNAME=		Crypt-CAST5_PP-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		12
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-CAST5_PP
COMMENT=		The CAST5 block cipher, implemented in pure Perl

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/CAST5_PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
