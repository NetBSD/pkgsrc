# $NetBSD: Makefile,v 1.10 2012/10/31 11:18:20 asau Exp $
#

DISTNAME=	IO-Interactive-0.0.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
