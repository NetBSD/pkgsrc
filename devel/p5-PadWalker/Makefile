# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:27 obache Exp $

DISTNAME=	PadWalker-1.92
PKGNAME=	p5-PadWalker-1.9.2
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RO/ROBIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PadWalker/
COMMENT=	Play with other peoples' lexical variables
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/PadWalker/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
