# $NetBSD: Makefile,v 1.7 2008/11/22 00:15:22 he Exp $
#

DISTNAME=	Text-Markdown-1.0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Markdown/
COMMENT=	Convert Markdown to HTML

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PERL5_PACKLIST=		auto/Text/Markdown/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
