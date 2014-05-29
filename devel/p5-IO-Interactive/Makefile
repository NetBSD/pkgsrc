# $NetBSD: Makefile,v 1.12 2014/05/29 23:35:59 wiz Exp $
#

DISTNAME=	IO-Interactive-0.0.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Interactive/
COMMENT=	Perl 5 module prodiving utilities for interactive I/O
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Interactive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
