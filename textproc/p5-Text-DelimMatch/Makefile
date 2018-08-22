# $NetBSD: Makefile,v 1.29 2018/08/22 09:46:59 wiz Exp $
#

DISTNAME=	DelimMatch-1.06a
PKGNAME=	p5-Text-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/DelimMatch/
COMMENT=	Find regexp delimited strings with proper nesting

WRKSRC=			${WRKDIR}/${DISTNAME:S/a$//}
PERL5_PACKLIST=		auto/Text/DelimMatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
