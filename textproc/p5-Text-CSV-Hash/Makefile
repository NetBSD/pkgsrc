# $NetBSD: Makefile,v 1.13 2002/10/08 09:39:27 abs Exp $

DISTNAME=		Text-CSV-Hash-0.15
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/Text-CSV-Hash/

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		http://www.mono.org/abs/tools/Text-CSV-Hash/
COMMENT=		perl5 module for hash based CSV usage

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/CSV/Hash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
