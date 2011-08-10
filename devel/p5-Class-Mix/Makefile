# $NetBSD: Makefile,v 1.5 2011/08/10 04:24:24 adam Exp $

DISTNAME=	Class-Mix-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Mix/
COMMENT=	Perl 5 module providing dynamic class mixing
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Params-Classify-[0-9]*:../../devel/p5-Params-Classify
DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/Mix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
