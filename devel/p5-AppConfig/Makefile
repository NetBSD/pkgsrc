# $NetBSD: Makefile,v 1.9 2004/11/23 22:50:19 jlam Exp $

DISTNAME=	AppConfig-1.56
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5apc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/ABW/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	Perl5 module for parsing config files and command line arguments

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/AppConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
