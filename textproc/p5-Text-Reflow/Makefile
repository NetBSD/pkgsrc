# $NetBSD: Makefile,v 1.27 2023/07/06 09:41:54 wiz Exp $

DISTNAME=		Text-Reflow-1.17
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Text-Reflow
COMMENT=		Reflowing of text using Knuth's paragraphing algorithm
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Reflow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
