# $NetBSD: Makefile,v 1.8 2012/10/23 19:51:18 asau Exp $

DISTNAME=	Unix-ConfigFile-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ssnodgra/${DISTNAME}
COMMENT=	Simple interfaces to various Unix configuration files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Unix/ConfigFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
