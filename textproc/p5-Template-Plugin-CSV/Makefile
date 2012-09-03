# $NetBSD: Makefile,v 1.4 2012/09/03 11:16:24 sno Exp $
#

DISTNAME=	Template-Plugin-CSV-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-CSV/
COMMENT=	Template::Toolkit plugin for generating CSV
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-CSV-[0-9]*:../../textproc/p5-Text-CSV

PERL5_PACKLIST=		auto/Template/Plugin/CSV/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
