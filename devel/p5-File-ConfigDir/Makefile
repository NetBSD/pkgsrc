# $NetBSD: Makefile,v 1.10 2014/05/29 23:35:54 wiz Exp $

DISTNAME=	File-ConfigDir-0.011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-ConfigDir
COMMENT=	Get directories of configuration files
LICENSE=	${PERL5_LICENSE}

# recommended modules ...
DEPENDS+=	p5-File-HomeDir>=0.50:../../devel/p5-File-HomeDir
DEPENDS+=	p5-List-MoreUtils>=0.22:../../devel/p5-List-MoreUtils

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/ConfigDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
