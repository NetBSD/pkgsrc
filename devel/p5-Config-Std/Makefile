# $NetBSD: Makefile,v 1.17 2017/06/05 14:22:46 ryoon Exp $

DISTNAME=	Config-Std-0.901
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BR/BRICKER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Std/
COMMENT=	Perl 5 module providing a simple configuration-file system
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Std-[0-9]*:../../devel/p5-Class-Std
#DEPENDS+=	{perl>=5.9.0,p5-version-[0-9]*}:../../devel/p5-version

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/Std/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
