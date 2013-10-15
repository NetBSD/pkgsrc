# $NetBSD: Makefile,v 1.28 2013/10/15 14:34:20 wen Exp $

DISTNAME=	Config-General-2.52
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cfg
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.daemon.de/ConfigGeneral
COMMENT=	Perl Generic Config module
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
