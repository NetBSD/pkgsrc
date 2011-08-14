# $NetBSD: Makefile,v 1.6 2011/08/14 15:14:16 obache Exp $

DISTNAME=	XML-Clean-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PK/PKUBANEK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~pkubanek/XML-Clean/
COMMENT=	Ensure, that *(HTML)* text pass throught an XML parser

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/XML/Clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
