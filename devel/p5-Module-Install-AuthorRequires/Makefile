# $NetBSD: Makefile,v 1.1 2015/04/28 12:15:56 mef Exp $

DISTNAME=	Module-Install-AuthorRequires-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/F/FL/FLORA/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~flora/Module-Install-AuthorRequires/
COMMENT=	Module::Install::AuthorRequires - declare author-only dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-NoTabs-[0-9]*:../../devel/p5-Test-NoTabs

PERL5_PACKLIST=	auto/Module/Install/AuthorRequires/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
