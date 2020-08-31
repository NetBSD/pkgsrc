# $NetBSD: Makefile,v 1.18 2020/08/31 18:12:06 wiz Exp $
#

DISTNAME=		Text-WikiCreole-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Text-WikiCreole
COMMENT=		Translate Wiki Creole markup into XHTML
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/WikiCreole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
