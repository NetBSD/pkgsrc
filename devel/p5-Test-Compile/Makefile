# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:40 obache Exp $
#

DISTNAME=	Test-Compile-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Compile/
COMMENT=	Perl 5 module to check whether Perl module files compile correctly
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Compile/.packlist

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Devel-CheckOS-[0-9]*:../../devel/p5-Devel-CheckOS
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
