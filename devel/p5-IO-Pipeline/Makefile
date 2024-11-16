# $NetBSD: Makefile,v 1.19 2024/11/16 12:04:25 wiz Exp $
#

DISTNAME=	IO-Pipeline-0.009002
PKGNAME=	p5-IO-Pipeline-0.9.2
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Pipeline
COMMENT=	Perl 5 module providing map and grep for filehandles, unix pipe style
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/IO/Pipeline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
