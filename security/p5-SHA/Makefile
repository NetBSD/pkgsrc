# $NetBSD: Makefile,v 1.35 2022/06/28 11:35:49 wiz Exp $
#

DISTNAME=		SHA-2.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=SHA/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/SHA
COMMENT=		Perl5 interface to the SHA1 algorithm

DEPENDS+=		p5-Digest-SHA1>=1.0:../../security/p5-Digest-SHA1

PERL5_PACKLIST=		auto/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
