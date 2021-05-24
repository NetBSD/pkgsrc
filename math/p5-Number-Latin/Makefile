# $NetBSD: Makefile,v 1.23 2021/05/24 19:53:01 wiz Exp $

DISTNAME=		Number-Latin-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		norm@sandbox.org.uk
HOMEPAGE=		https://metacpan.org/release/Number-Latin
COMMENT=		Perl module for "lower/upper-latin" numbering system
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Latin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
