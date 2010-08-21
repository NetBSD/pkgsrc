# $NetBSD: Makefile,v 1.9 2010/08/21 16:33:39 seb Exp $

DISTNAME=	ExtUtils-AutoInstall-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~autrijus/ExtUtils-AutoInstall/
COMMENT=	Lets Makefile.PL automatically install dependencies

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Sort-Versions>=1.2:../../devel/p5-Sort-Versions

PERL5_PACKLIST=		auto/ExtUtils/AutoInstall/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
