# $NetBSD: Makefile,v 1.11 2018/08/22 09:44:19 wiz Exp $
#

DISTNAME=	Module-Versions-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}
EXTRACT_SUFX=	.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Module-Versions/
COMMENT=		Perl 5 module to handle versions of loaded modules
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/Versions/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
