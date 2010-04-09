# $NetBSD: Makefile,v 1.1.1.1 2010/04/09 08:17:41 sno Exp $

DISTNAME=	Attribute-Lexical-0.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Attribute-Lexical/
COMMENT=	Sane scoping of function/variable attributes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lexical-SealRequireHints>=0.001:../../devel/p5-Lexical-SealRequireHints
DEPENDS+=	p5-Params-Classify-[0-9]*:../../devel/p5-Params-Classify

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# none

PERL5_PACKLIST=		auto/Attribute/Lexical/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
