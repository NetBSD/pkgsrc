# $NetBSD: Makefile,v 1.9 2004/01/20 12:26:50 agc Exp $
#

DISTNAME=	DelimMatch-1.06a
PKGNAME=	p5-Text-${DISTNAME}
SVR4_PKGNAME=	p5tdm
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/DelimMatch/
COMMENT=	Find regexp delimited strings with proper nesting

WRKSRC=			${WRKDIR}/${DISTNAME:S/a$//}
USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/DelimMatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
