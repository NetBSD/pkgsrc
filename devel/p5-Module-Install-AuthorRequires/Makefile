# $NetBSD: Makefile,v 1.5 2017/06/12 12:37:28 maya Exp $

DISTNAME=	Module-Install-AuthorRequires-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/F/FL/FLORA/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~flora/Module-Install-AuthorRequires/
COMMENT=	Module::Install::AuthorRequires - declare author-only dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-NoTabs-[0-9]*:../../devel/p5-Test-NoTabs

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Module/Install/AuthorRequires/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
