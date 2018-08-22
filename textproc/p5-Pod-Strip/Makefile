# $NetBSD: Makefile,v 1.13 2018/08/22 09:46:54 wiz Exp $
#

DISTNAME=	Pod-Strip-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Strip/
COMMENT=	Perl5 module to remove POD from Perl code

#DEPENDS+=	{perl>=5.9.3,p5-Pod-Simple>=3.0}:../../textproc/p5-Pod-Simple

PERL5_PACKLIST=	auto/Pod/Strip/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
