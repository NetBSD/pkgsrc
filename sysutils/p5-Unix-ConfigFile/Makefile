# $NetBSD: Makefile,v 1.9 2013/05/31 12:42:04 wiz Exp $

DISTNAME=	Unix-ConfigFile-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ssnodgra/${DISTNAME}
COMMENT=	Simple interfaces to various Unix configuration files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Unix/ConfigFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
