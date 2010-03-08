# $NetBSD: Makefile,v 1.2 2010/03/08 18:29:44 sno Exp $
#

DISTNAME=	Padre-Plugin-PerlTidy-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-PerlTidy/
COMMENT=	Format perl files in Padre using Perl::Tidy
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Padre>=0.54:../../editors/p5-Padre
DEPENDS+=	p5-Perl-Tidy-[0-9]*:../../devel/p5-Perl-Tidy

BUILD_DEPENDS+=	p5-Locale-Msgfmt>=0.14:../../devel/p5-Locale-Msgfmt

PERL5_PACKLIST=		auto/Padre/Plugin/PerlTidy/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
