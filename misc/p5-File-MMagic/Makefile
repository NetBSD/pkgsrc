# $NetBSD: Makefile,v 1.9 2004/04/21 17:22:05 taca Exp $

DISTNAME=		File-MMagic-1.22
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fim
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/KNOK/
COMMENT=		Perl5 module to guess file types

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/MMagic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
