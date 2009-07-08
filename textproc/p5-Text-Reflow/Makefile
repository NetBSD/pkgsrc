# $NetBSD: Makefile,v 1.5 2009/07/08 11:24:23 sno Exp $
#

DISTNAME=		Text-Reflow-1.07
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5rfl
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Reflow/
COMMENT=		Reflowing of text using Knuth's paragraphing algorithm
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Reflow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
