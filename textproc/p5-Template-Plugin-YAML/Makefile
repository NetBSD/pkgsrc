# $NetBSD: Makefile,v 1.11 2018/08/22 09:46:57 wiz Exp $
#

DISTNAME=	Template-Plugin-YAML-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-YAML/
COMMENT=	Plugin interface to YAML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

PERL5_PACKLIST=		auto/Template/Plugin/YAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
