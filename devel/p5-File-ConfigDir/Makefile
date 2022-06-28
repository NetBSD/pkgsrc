# $NetBSD: Makefile,v 1.24 2022/06/28 11:32:24 wiz Exp $

DISTNAME=	File-ConfigDir-0.021
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-ConfigDir
COMMENT=	Get directories of configuration files
LICENSE=	${PERL5_LICENSE}

# recommended modules ...
DEPENDS+=	p5-File-HomeDir>=0.50:../../devel/p5-File-HomeDir
DEPENDS+=	p5-List-MoreUtils>=0.22:../../devel/p5-List-MoreUtils

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Without-Module-[0-9]*:../../devel/p5-Test-Without-Module

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/ConfigDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
