# $NetBSD: Makefile,v 1.5 2009/05/21 12:14:26 sno Exp $

DISTNAME=	Text-Context-EitherSide-1.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Text-Context-EitherSide
COMMENT=	Get n words either side of search keywords
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_REQD+=	5.6.0
PERL5_PACKLIST=	auto/Text/Context/EitherSide/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
