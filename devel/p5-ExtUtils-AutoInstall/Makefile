# $NetBSD: Makefile,v 1.5 2005/11/22 22:58:02 wiz Exp $

DISTNAME=	ExtUtils-AutoInstall-0.63
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~autrijus/ExtUtils-AutoInstall/
COMMENT=	Lets Makefile.PL automatically install dependencies

DEPENDS+=	p5-Sort-Versions>=1.2:../../devel/p5-Sort-Versions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/ExtUtils/AutoInstall/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
