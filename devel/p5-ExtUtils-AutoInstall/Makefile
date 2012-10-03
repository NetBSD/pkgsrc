# $NetBSD: Makefile,v 1.11 2012/10/03 21:54:57 wiz Exp $

DISTNAME=	ExtUtils-AutoInstall-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-AutoInstall/
COMMENT=	Lets Makefile.PL automatically install dependencies
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Sort-Versions>=1.2:../../devel/p5-Sort-Versions

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--skip
PERL5_PACKLIST=		auto/ExtUtils/AutoInstall/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
