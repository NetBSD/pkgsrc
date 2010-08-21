# $NetBSD: Makefile,v 1.7 2010/08/21 16:36:06 seb Exp $
#

DISTNAME=		Text-Reflow-1.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5rfl
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Reflow/
COMMENT=		Reflowing of text using Knuth's paragraphing algorithm
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Reflow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
