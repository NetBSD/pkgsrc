# $NetBSD: Makefile,v 1.5 2002/09/26 11:25:08 seb Exp $
#

DISTNAME=	DelimMatch-1.03
PKGNAME=	p5-Text-DelimMatch-1.03
SVR4_PKGNAME=	p5tdm
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/DelimMatch/
COMMENT=	Find regexp delimited strings with proper nesting

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/DelimMatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
