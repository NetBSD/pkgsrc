# $NetBSD: Makefile,v 1.11 2013/03/02 10:44:44 tron Exp $
#

DISTNAME=		Text-Reflow-1.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5rfl
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Reflow/
COMMENT=		Reflowing of text using Knuth's paragraphing algorithm
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Reflow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
