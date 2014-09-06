# $NetBSD: Makefile,v 1.1 2014/09/06 14:45:49 wiz Exp $

DISTNAME=	Test-YAML-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-YAML/
COMMENT=	Testing Module for YAML Implementations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/YAML/.packlist

USE_TOOLS+=	bash:run
REPLACE_BASH+=	bin/test-yaml

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
