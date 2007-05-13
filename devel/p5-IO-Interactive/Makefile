# $NetBSD: Makefile,v 1.1.1.1 2007/05/13 14:38:14 seb Exp $
#

DISTNAME=	IO-Interactive-v0.0.3
PKGNAME=	p5-IO-Interactive-0.0.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Interactive/
COMMENT=	Perl 5 module prodiving utilities for interactive I/O

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Interactive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
