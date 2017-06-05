# $NetBSD: Makefile,v 1.27 2017/06/05 14:22:41 ryoon Exp $

DISTNAME=	Class-Autouse-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Autouse/
COMMENT=	Run-time class loading on first method call
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-AutoInstall>=0.61:../../devel/p5-ExtUtils-AutoInstall
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.19}:../../devel/p5-Scalar-List-Utils

PERL5_PACKLIST=		auto/Class/Autouse/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
