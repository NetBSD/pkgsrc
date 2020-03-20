# $NetBSD: Makefile,v 1.23 2020/03/20 11:57:28 nia Exp $

DISTNAME=	CPANPLUS-0.9906
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPANPLUS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpanplus.sourceforge.net/
COMMENT=	Ameliorated interface to the CPAN
LICENSE=	${PERL5_LICENSE}

INSTALL_TARGET=	pure_install

DEPENDS+=	p5-Log-Message-[0-9]*:../../devel/p5-Log-Message
DEPENDS+=	p5-Object-Accessor-[0-9]*:../../devel/p5-Object-Accessor
DEPENDS+=	p5-Test-Reporter-[0-9]*:../../devel/p5-Test-Reporter
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

TEST_DEPENDS+=	p5-Archive-Extract-[0-9]*:../../archivers/p5-Archive-Extract
TEST_DEPENDS+=	p5-Term-UI-[0-9]*:../../devel/p5-Term-UI
TEST_DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
TEST_DEPENDS+=	p5-Log-Message-Simple-[0-9]*:../../devel/p5-Log-Message-Simple
TEST_DEPENDS+=	p5-Package-Constants-[0-9]*:../../devel/p5-Package-Constants

PERL5_PACKLIST=	auto/CPANPLUS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
