# $NetBSD: Makefile,v 1.24 2022/06/28 11:34:42 wiz Exp $

DISTNAME=		Number-Latin-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		16
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		norm@sandbox.org.uk
HOMEPAGE=		https://metacpan.org/release/Number-Latin
COMMENT=		Perl module for "lower/upper-latin" numbering system
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Latin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
