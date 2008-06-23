# $NetBSD: Makefile,v 1.1.1.1 2008/06/23 03:46:48 abs Exp $

DISTNAME=	UNIVERSAL-isa-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHROMATIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-isa/
COMMENT=	Hack around people calling UNIVERSAL::isa() as a function

DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/UNIVERSAL/isa/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
