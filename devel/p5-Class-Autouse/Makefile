# $NetBSD: Makefile,v 1.1.1.1 2005/03/03 04:21:33 epg Exp $

DISTNAME=	Class-Autouse-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Run-time class loading on first method call

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Autouse/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

DEPENDS+=	p5-ExtUtils-AutoInstall>=0.61:../../devel/p5-ExtUtils-AutoInstall

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
