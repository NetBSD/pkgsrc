# $NetBSD: Makefile,v 1.18 2018/08/22 09:44:38 wiz Exp $
#

DISTNAME=	Smart-Comments-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Smart-Comments/
COMMENT=	Perl 5 module to insert debugging and tracking code easily
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Smart/Comments/.packlist
#PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
