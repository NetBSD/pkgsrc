# $NetBSD: Makefile,v 1.17 2023/07/06 09:41:49 wiz Exp $
#

DISTNAME=	Text-Brew-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Brew
COMMENT=	Perl module for configurable and analyzable edit distances
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Brew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
