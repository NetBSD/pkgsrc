# $NetBSD: Makefile,v 1.3 2011/08/10 10:06:58 adam Exp $

DISTNAME=	CPAN-FindDependencies-2.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-FindDependencies/
COMMENT=	Perl 5 module to find dependencies for modules on the CPAN
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Capture-Tiny>=0.05:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Devel-CheckOS>=1.52:../../devel/p5-Devel-CheckOS
DEPENDS+=	p5-File-Temp>=0.19:../../devel/p5-File-Temp
DEPENDS+=	p5-libwww>=1.41:../../www/p5-libwww
DEPENDS+=	p5-Parse-CPAN-Packages>=2.31:../../devel/p5-Parse-CPAN-Packages
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI # really URI::file>=4.13
DEPENDS+=	p5-YAML-Tiny>=1.36:../../textproc/p5-YAML-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CPAN/FindDependencies/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
