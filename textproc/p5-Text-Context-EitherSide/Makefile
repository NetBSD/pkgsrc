# $NetBSD: Makefile,v 1.3 2008/07/20 16:09:35 heinz Exp $

DISTNAME=	Text-Context-EitherSide-1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Text-Context-EitherSide
COMMENT=	Get n words either side of search keywords

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_REQD+=	5.6.0
PERL5_PACKLIST=	auto/Text/Context/EitherSide/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
