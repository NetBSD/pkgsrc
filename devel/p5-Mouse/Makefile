# $NetBSD: Makefile,v 1.13 2009/09/09 20:07:39 seb Exp $

DISTNAME=	Mouse-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SU/SUNNAVY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mouse/
COMMENT=	Perl module implementing an extension of the perl object system
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

DEPENDS+=	p5-Class-Method-Modifiers>=1.01:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Simple>=0.80:../../devel/p5-Test-Simple
#BUILD_DEPENDS+=	p5-Test-Output>=0:../../devel/p5-Test-Output

PERL5_PACKLIST=	auto/Mouse/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
