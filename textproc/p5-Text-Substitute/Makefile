# $NetBSD: Makefile,v 1.8 2004/02/21 07:40:35 snj Exp $

DISTNAME=		Text-Substitute-0.15
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/Text-Substitute/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.mono.org/abs/tools/Text-Substitute/
COMMENT=		Perl5 module for text substitution from hashes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Substitute/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
