# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:01 seb Exp $
#

DISTNAME=	Template-Plugin-YAML-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-YAML/
COMMENT=	Plugin interface to YAML
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

PERL5_PACKLIST=		auto/Template/Plugin/YAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
