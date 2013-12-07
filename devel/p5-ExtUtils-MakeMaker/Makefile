# $NetBSD: Makefile,v 1.26 2013/12/07 00:54:05 wiz Exp $

DISTNAME=	ExtUtils-MakeMaker-6.84
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-MakeMaker/
COMMENT=	Write a Makefile for an extension module from a Makefile.PL
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Parse-CPAN-Meta>=1.4405:../../devel/p5-Parse-CPAN-Meta
DEPENDS+=	p5-CPAN-Meta>=2.112150:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-File-Copy-Recursive>=0.38:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-JSON-PP>=2.27203:../../converters/p5-JSON-PP
# perhaps package JSON::PP::Compat5006, otherwise 'make complains:
#Using included version of JSON::PP::Compat5006 (1.09) because it is not already installed.
# on the other hand, it's only needed for Perl-5.6 ...

PERL5_PACKLIST=		auto/ExtUtils/MakeMaker/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f -exec ${RM} {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
