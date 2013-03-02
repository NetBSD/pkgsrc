# $NetBSD: Makefile,v 1.8 2013/03/02 10:44:44 tron Exp $
#

DISTNAME=	Text-Textile-2.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Textile/
COMMENT=	Perl impementation of the Textile formatting language
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Textile/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
