# $NetBSD: Makefile,v 1.9 2009/11/11 06:34:29 seb Exp $
#

DISTNAME=	Text-Markdown-1.000029
PKGNAME=	p5-Text-Markdown-1.0.29
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
BUILD_DEPENDS+= p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences

PERL5_PACKLIST=		auto/Text/Markdown/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
