# $NetBSD: Makefile,v 1.19 2011/12/08 22:44:24 hiramatsu Exp $

DISTNAME=	ExtUtils-MakeMaker-6.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTROUT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-MakeMaker/
COMMENT=	Write a Makefile for an extension module from a Makefile.PL
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-CPAN-Meta>=2.112150:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-Parse-CPAN-Meta>=1.4401:../../devel/p5-Parse-CPAN-Meta
DEPENDS+=	p5-File-Copy-Recursive>=0.38:../../sysutils/p5-File-Copy-Recursive
# perhaps package JSON::PP::Compat5006, otherwise 'make complains:
#Using included version of JSON::PP::Compat5006 (1.09) because it is not already installed.
# on the other hand, it's only needed for Perl-5.6 ...

PERL5_PACKLIST=		auto/ExtUtils/MakeMaker/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f -exec ${RM} {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
