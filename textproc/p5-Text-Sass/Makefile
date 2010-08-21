# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:07 seb Exp $

DISTNAME=	Text-Sass-0.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Sass/
COMMENT=	Perl 5 module implementing Sass
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text-Sass/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Readonly>=1.03:../../devel/p5-Readonly

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
