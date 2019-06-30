# $NetBSD: Makefile,v 1.2 2019/06/30 20:15:40 nia Exp $

DISTNAME=	Regexp-Trie-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-Trie
COMMENT=	Builds trie-ized regexp
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Trie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
