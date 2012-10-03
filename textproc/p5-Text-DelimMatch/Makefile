# $NetBSD: Makefile,v 1.20 2012/10/03 21:58:02 wiz Exp $
#

DISTNAME=	DelimMatch-1.06a
PKGNAME=	p5-Text-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5tdm
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/DelimMatch/
COMMENT=	Find regexp delimited strings with proper nesting

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME:S/a$//}
PERL5_PACKLIST=		auto/Text/DelimMatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
