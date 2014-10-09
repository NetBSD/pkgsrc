# $NetBSD: Makefile,v 1.15 2014/10/09 14:06:16 wiz Exp $

DISTNAME=	ExtUtils-AutoInstall-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-AutoInstall/
COMMENT=	Lets Makefile.PL automatically install dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sort-Versions>=1.2:../../devel/p5-Sort-Versions

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--skip
PERL5_PACKLIST=		auto/ExtUtils/AutoInstall/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
