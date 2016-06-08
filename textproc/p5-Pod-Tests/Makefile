# $NetBSD: Makefile,v 1.13 2016/06/08 19:24:33 wiz Exp $

DISTNAME=		Pod-Tests-1.19
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Pod-Tests/
COMMENT=		Perl5 module that extracts embedded tests and code examples from POD

PERL5_PACKLIST=		auto/Pod/Tests/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
