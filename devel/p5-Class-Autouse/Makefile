# $NetBSD: Makefile,v 1.10 2006/07/19 22:35:28 wiz Exp $

DISTNAME=	Class-Autouse-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Autouse/
COMMENT=	Run-time class loading on first method call

DEPENDS+=	p5-ExtUtils-AutoInstall>=0.61:../../devel/p5-ExtUtils-AutoInstall
DEPENDS+=	p5-Scalar-List-Utils>=1.18:../../devel/p5-Scalar-List-Utils

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Autouse/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
