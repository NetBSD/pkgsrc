# $NetBSD: Makefile,v 1.18 2022/06/28 11:32:43 wiz Exp $
#

DISTNAME=	Mac-SystemDirectory-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mac-SystemDirectory
COMMENT=	Locate Mac OS X Standard System Directories
LICENSE=	${PERL5_LICENSE}

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/Mac/SystemDirectory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
