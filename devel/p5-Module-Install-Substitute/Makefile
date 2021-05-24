# $NetBSD: Makefile,v 1.19 2021/05/24 19:51:04 wiz Exp $

DISTNAME=	Module-Install-Substitute-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Install-Substitute
COMMENT=	Perl5 module to substitute values into files before install

DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install
DEPENDS+=	p5-Test-File-Contents-[0-9]*:../../devel/p5-Test-File-Contents

PERL5_PACKLIST=	auto/Module/Install/Substitute/.packlist

pre-test:
	${INSTALL_DATA_DIR} ${WRKSRC}/t/data/input/02basics/to

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
