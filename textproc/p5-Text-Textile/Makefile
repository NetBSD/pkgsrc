# $NetBSD: Makefile,v 1.19 2021/05/24 19:54:47 wiz Exp $
#

DISTNAME=	Text-Textile-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Textile
COMMENT=	Perl implementation of the Textile formatting language
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Textile/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
