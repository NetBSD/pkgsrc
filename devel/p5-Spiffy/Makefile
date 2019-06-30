# $NetBSD: Makefile,v 1.29 2019/06/30 20:15:44 nia Exp $

DISTNAME=	Spiffy-0.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Spiffy
COMMENT=	Object-oriented Perl framework
LICENSE=	${PERL5_LICENSE}

# optional requirement for spiffy_filter() sub
DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter

PERL5_PACKLIST=	auto/Spiffy/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
