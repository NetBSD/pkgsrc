# $NetBSD: Makefile,v 1.4 2009/05/21 13:20:14 sno Exp $
#

DISTNAME=		Text-Reflow-1.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5rfl
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Reflow/
COMMENT=		Reflowing of text using Knuth's paragraphing algorithm

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Reflow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
