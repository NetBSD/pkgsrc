# $NetBSD: Makefile,v 1.1.1.1 2007/05/11 16:25:23 seb Exp $
#

DISTNAME=	Smart-Comments-v1.0.2
PKGNAME=	p5-Smart-Comments-1.0.2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Smart-Comments/
COMMENT=	Perl 5 module to insert debugging and tracking code easily

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Smart/Comments/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
