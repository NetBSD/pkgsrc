# $NetBSD: Makefile,v 1.7 2011/11/25 05:55:03 hiramatsu Exp $

DISTNAME=	Method-Signatures-Simple-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RH/RHESA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Method::Signatures::Simple
COMMENT=	Basic signatures method declarations, without source filters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Declare>=0.003001:../../devel/p5-Devel-Declare

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Method/Signatures/Simple/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
