# $NetBSD: Makefile,v 1.1.1.1 2012/01/08 02:27:48 schmonz Exp $
#

DISTNAME=		Text-Markdown-Discount-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Markdown-Discount/
COMMENT=		Convert Markdown to (X)HTML
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Markdown/Discount/.packlist
USE_LANGUAGES=		c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
