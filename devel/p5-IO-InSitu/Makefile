# $NetBSD: Makefile,v 1.13 2018/08/22 09:44:08 wiz Exp $
#

DISTNAME=	IO-InSitu-0.0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-InSitu/
COMMENT=	Perl 5 module to do in-situ processing on a file

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/InSitu/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
