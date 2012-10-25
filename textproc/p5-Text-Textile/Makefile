# $NetBSD: Makefile,v 1.7 2012/10/25 06:56:30 asau Exp $
#

DISTNAME=	Text-Textile-2.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Textile/
COMMENT=	Perl impementation of the Textile formatting language
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Textile/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
