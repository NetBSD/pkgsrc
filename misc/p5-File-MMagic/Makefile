# $NetBSD: Makefile,v 1.12 2005/04/11 21:46:38 tv Exp $

DISTNAME=		File-MMagic-1.22
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fim
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/KNOK/
COMMENT=		Perl5 module to guess file types

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/MMagic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
