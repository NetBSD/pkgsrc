# $NetBSD: Makefile,v 1.5 2010/08/21 16:34:02 seb Exp $

DISTNAME=	Module-Install-Substitute-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5mis
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-Substitute/
COMMENT=	Perl5 module to substitute values into files before install

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install
DEPENDS+=	p5-Test-File-Contents-[0-9]*:../../devel/p5-Test-File-Contents

PERL5_PACKLIST=	auto/Module/Install/Substitute/.packlist

pre-test:
	${INSTALL_DATA_DIR} ${WRKSRC}/t/data/input/02basics/to

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
