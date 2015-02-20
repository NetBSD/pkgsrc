# $NetBSD: Makefile,v 1.19 2015/02/20 10:11:24 wen Exp $

DISTNAME=		Getopt-Long-2.44
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Getopt-Long/
COMMENT=		Extended processing of command line options
LICENSE=		${PERL5_LICENSE}

REPLACE_PERL+=	lib/Getopt/Long.pm

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Getopt/Long/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
