# $NetBSD: Makefile,v 1.9 2014/05/29 23:36:14 wiz Exp $
#

DISTNAME=	Regexp-Parser-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-Parser/
COMMENT=	Perl 5 base class for parsing regexes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
