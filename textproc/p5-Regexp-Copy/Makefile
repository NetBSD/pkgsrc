# $NetBSD: Makefile,v 1.18 2023/07/06 09:41:45 wiz Exp $
#

DISTNAME=		Regexp-Copy-0.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Regexp-Copy
COMMENT=		Perl5 module to copy Regexp objects
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Regexp/Copy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
