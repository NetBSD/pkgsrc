# $NetBSD: Makefile,v 1.18 2016/06/08 19:24:39 wiz Exp $
#

DISTNAME=		Text-Reflow-1.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Reflow/
COMMENT=		Reflowing of text using Knuth's paragraphing algorithm
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Reflow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
