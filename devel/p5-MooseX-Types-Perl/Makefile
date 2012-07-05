# $NetBSD: Makefile,v 1.2 2012/07/05 16:53:29 sno Exp $
#

DISTNAME=	MooseX-Types-Perl-0.101341
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-Perl/
COMMENT=	Moose types that check against Perl syntax
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MooseX/Types/Perl/.packlist

DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util

BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
