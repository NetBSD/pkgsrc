# $NetBSD: Makefile,v 1.4 2002/09/26 11:08:23 seb Exp $

DISTNAME=		Text-Substitute-0.14
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/Text-Substitute/

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		http://www.mono.org/abs/tools/Text-Substitute/
COMMENT=		perl5 module for text substition from hashes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Substitute/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
