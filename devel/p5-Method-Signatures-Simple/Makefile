# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:17 obache Exp $

DISTNAME=	Method-Signatures-Simple-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
