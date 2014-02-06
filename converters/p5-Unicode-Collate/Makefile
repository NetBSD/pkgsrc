# $NetBSD: Makefile,v 1.9 2014/02/06 12:54:50 abs Exp $

DISTNAME=	Unicode-Collate-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-Collate/
COMMENT=	Perl5 implementation of Unicode Collation Algorithm
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Unicode/Collate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
