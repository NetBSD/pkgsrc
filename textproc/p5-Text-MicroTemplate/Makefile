# $NetBSD: Makefile,v 1.24 2023/07/06 09:41:53 wiz Exp $

DISTNAME=	Text-MicroTemplate-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-MicroTemplate
COMMENT=	Perl 5 module providing a template engine
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Text/MicroTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
