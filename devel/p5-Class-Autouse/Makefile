# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:29 tv Exp $

DISTNAME=	Class-Autouse-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Run-time class loading on first method call

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Autouse/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

DEPENDS+=	p5-ExtUtils-AutoInstall>=0.61:../../devel/p5-ExtUtils-AutoInstall

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
