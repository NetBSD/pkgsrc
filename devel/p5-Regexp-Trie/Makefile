# $NetBSD: Makefile,v 1.1 2019/02/09 07:58:03 wen Exp $

DISTNAME=	Regexp-Trie-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-Trie/
COMMENT=	Builds trie-ized regexp
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Trie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
