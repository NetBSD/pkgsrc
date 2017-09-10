# $NetBSD: Makefile,v 1.23 2017/09/10 21:28:57 wiz Exp $

DISTNAME=	File-Which-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Which/
COMMENT=	Portable implementation of the 'which' utility
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Test-Script>=1.05:../../devel/p5-Test-Script

PERL5_PACKLIST=		auto/File/Which/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
