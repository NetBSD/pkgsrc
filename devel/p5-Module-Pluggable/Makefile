# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:23 jlam Exp $
#

DISTNAME=	Module-Pluggable-2.8
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mpl
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Pluggable/
COMMENT=	Perl 5 module for automatically adding the ability to have plugins to modules

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
