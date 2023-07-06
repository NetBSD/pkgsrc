# $NetBSD: Makefile,v 1.21 2023/07/06 09:41:57 wiz Exp $
#

DISTNAME=		Text-WikiCreole-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Text-WikiCreole
COMMENT=		Translate Wiki Creole markup into XHTML
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/WikiCreole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
