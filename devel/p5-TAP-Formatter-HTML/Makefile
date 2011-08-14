# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:37 obache Exp $
#

DISTNAME=		TAP-Formatter-HTML-0.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SP/SPURKIS/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/S/SP/SPURKIS/
COMMENT=	TAP Test Harness output delegate for html output
LICENSE=  ${PERL5_LICENSE}

DEPENDS+=	p5-Test-Harness>=3.10:../../devel/p5-Test-Harness
DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit
DEPENDS+=	p5-URI>=1.35:../../www/p5-URI
DEPENDS+=	p5-accessors>=0.2:../../devel/p5-accessors

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TAP/Formatter/HTML/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
