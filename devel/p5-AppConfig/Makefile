# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:19 jlam Exp $

DISTNAME=	AppConfig-1.56
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5apc
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/ABW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	Perl5 module for parsing config files and command line arguments

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/AppConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
