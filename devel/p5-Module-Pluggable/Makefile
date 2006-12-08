# $NetBSD: Makefile,v 1.6 2006/12/08 14:58:15 obache Exp $
#

DISTNAME=	Module-Pluggable-3.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mpl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Pluggable/
COMMENT=	Perl 5 module for automatically adding the ability to have plugins to modules

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
