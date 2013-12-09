# $NetBSD: Makefile,v 1.2 2013/12/09 14:17:47 obache Exp $
#

DISTNAME=	constant-def-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MO/MONS/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mons/constant-def-0.01/lib/constant/def.pm
COMMENT=	Perl pragma to declare previously undeclared constants
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.13.11,p5-Test-Simple>=0.98}:../../devel/p5-Test-Simple
DEPENDS+=	{perl>=5.8.7,p5-constant>=1.05}:../../devel/p5-constant
DEPENDS+=	p5-ex-lib>=0.03:../../devel/p5-ex-lib

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
