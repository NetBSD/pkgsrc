# $NetBSD: Makefile,v 1.17 2019/06/30 20:16:54 nia Exp $

DISTNAME=		Pod-Tests-1.20
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Pod-Tests
COMMENT=		Perl5 module that extracts embedded tests and code examples from POD

PERL5_PACKLIST=		auto/Pod/Tests/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
