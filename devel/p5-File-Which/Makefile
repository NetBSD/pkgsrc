# $NetBSD: Makefile,v 1.19 2016/03/03 12:46:19 wiz Exp $

DISTNAME=	File-Which-1.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Which/
COMMENT=	Portable implementation of the 'which' utility
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Test-Script>=1.05:../../devel/p5-Test-Script
#BUILD_DEPENDS+=		{perl>=5.10.1,p5-Test-Simple>=0.80}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/File/Which/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
