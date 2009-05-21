# $NetBSD: Makefile,v 1.9 2009/05/21 13:25:17 sno Exp $
#

DISTNAME=	Text-RewriteRules-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-RewriteRules/
COMMENT=	Perl 5 module to rewrite text using regexp-based rules
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/RewriteRules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
