# $NetBSD: Makefile,v 1.33 2023/07/06 09:41:54 wiz Exp $
#

DISTNAME=	Text-Quoted-2.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Quoted
COMMENT=	Extract the structure of a quoted mail message
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Autoformat>=1.04:../../textproc/p5-Text-Autoformat

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/Quoted/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
