# $NetBSD: Makefile,v 1.2 2014/05/29 23:36:04 wiz Exp $

DISTNAME=	Module-Install-AuthorTests-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-AuthorTests/
COMMENT=	Perl 5 module for specifying author-only tests
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Module/Install/AuthorTests/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
