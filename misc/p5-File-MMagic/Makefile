# $NetBSD: Makefile,v 1.7 2003/07/21 17:01:23 martti Exp $

DISTNAME=		File-MMagic-1.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fim
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/
COMMENT=		Perl5 module to guess file types

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/MMagic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
