# $NetBSD: Makefile,v 1.3 2014/07/07 03:01:01 wen Exp $

DISTNAME=	ExtUtils-Config-0.008
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Config/
COMMENT=	Wrapper for configuration of Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/Config/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
