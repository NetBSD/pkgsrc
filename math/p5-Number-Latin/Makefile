# $NetBSD: Makefile,v 1.3 2004/12/20 11:31:05 grant Exp $

DISTNAME=		Number-Latin-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		Perl module for "lower/upper-latin" numbering system

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Number/Latin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
