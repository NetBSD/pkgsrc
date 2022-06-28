# $NetBSD: Makefile,v 1.21 2022/06/28 11:36:23 wiz Exp $

DISTNAME=		Pod-Tests-1.20
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Pod-Tests
COMMENT=		Perl5 module that extracts embedded tests and code examples from POD

PERL5_PACKLIST=		auto/Pod/Tests/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
