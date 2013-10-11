# $NetBSD: Makefile,v 1.7 2013/10/11 11:30:03 wiz Exp $

DISTNAME=	File-ConfigDir-0.007
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-ConfigDir/
COMMENT=	Get directories of configuration files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir>=0.50:../../devel/p5-File-HomeDir
DEPENDS+=	p5-List-MoreUtils>=0.22:../../devel/p5-List-MoreUtils

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/ConfigDir/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
