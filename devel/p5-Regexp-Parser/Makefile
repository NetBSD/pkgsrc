# $NetBSD: Makefile,v 1.7 2012/10/31 11:18:52 asau Exp $
#

DISTNAME=	Regexp-Parser-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-Parser/
COMMENT=	Perl 5 base class for parsing regexes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
