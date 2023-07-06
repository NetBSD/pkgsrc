# $NetBSD: Makefile,v 1.29 2023/07/06 09:41:27 wiz Exp $

DISTNAME=		Mozilla-CA-20221114
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mozilla/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Mozilla-CA
COMMENT=		Mozilla's CA cert bundle for Perl
LICENSE=		mpl-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mozilla/CA/.packlist
REPLACE_PERL+=		mk-ca-bundle.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
