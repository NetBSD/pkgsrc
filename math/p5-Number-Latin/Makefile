# $NetBSD: Makefile,v 1.1.1.1 2002/10/18 21:55:32 abs Exp $

DISTNAME=		Number-Latin-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		Perl module for "lower/upper-latin" numbering system

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Number/Latin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
