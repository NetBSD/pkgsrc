# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 15:52:30 sno Exp $
#

DISTNAME=	Perl-APIReference-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl-APIReference/
COMMENT=	Programmatically query the perlapi
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-XSAccessor>=1.05:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny
DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

PERL5_PACKLIST=		auto/Perl/APIReference/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
