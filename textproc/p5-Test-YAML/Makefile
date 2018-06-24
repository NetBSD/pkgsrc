# $NetBSD: Makefile,v 1.9 2018/06/24 09:13:29 wiz Exp $

DISTNAME=	Test-YAML-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-YAML/
COMMENT=	Testing Module for YAML Implementations
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Base>=0.86:../../devel/p5-Test-Base

PERL5_PACKLIST=		auto/Test/YAML/.packlist

# Workaround: to avoid a WRKREF error
DEPENDS+=	bash-[0-9]*:../../shells/bash
#USE_TOOLS+=	bash:run
#REPLACE_BASH+=	bin/test-yaml

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
