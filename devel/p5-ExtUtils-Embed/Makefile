# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:18 wiz Exp $

DISTNAME=	ExtUtils-Embed-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Embed/
COMMENT=	Utilities for embedding Perl in C/C++ applications
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils-Embed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
