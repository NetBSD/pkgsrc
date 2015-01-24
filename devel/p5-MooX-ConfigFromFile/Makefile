# $NetBSD: Makefile,v 1.4 2015/01/24 10:26:17 wen Exp $

DISTNAME=	MooX-ConfigFromFile-0.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rehsack/MooX-ConfigFromFile/
COMMENT=	Moo eXtension for initializing objects from config file
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-Any-[0-9]*:../../devel/p5-Config-Any
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-MooX-File-ConfigDir-[0-9]*:../../devel/p5-MooX-File-ConfigDir
BUILD_DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON

PERL5_PACKLIST=		auto/MooX/ConfigFromFile/.packlist
#PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
