# $NetBSD: Makefile,v 1.6 2019/08/11 13:23:46 wiz Exp $
#

DISTNAME=		Text-Roman-3.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Text-Roman
COMMENT=		Allows conversion between Roman and Arabic algarisms
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Roman/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
