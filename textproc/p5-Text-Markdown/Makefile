# $NetBSD: Makefile,v 1.8 2009/09/12 19:57:27 sno Exp $
#

DISTNAME=	Text-Markdown-1.0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Markdown/
COMMENT=	Convert Markdown to HTML
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-File-Slurp>=9999.08:../../devel/p5-File-Slurp
BUILD_DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Text/Markdown/.packlist
PERL5_MODULE_TYPE=	Module::Install
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
