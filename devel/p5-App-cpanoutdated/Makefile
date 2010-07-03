# $NetBSD: Makefile,v 1.1.1.1 2010/07/03 06:20:35 seb Exp $
#

DISTNAME=	App-cpanoutdated-0.08
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-cpanoutdated/
COMMENT=	Detect outdated CPAN modules in your environment
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/App/cpanoutdated/.packlist

DEPENDS+=	{perl>=5.12,p5-ExtUtils-MakeMaker>=6.56}:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
