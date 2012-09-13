# $NetBSD: Makefile,v 1.7 2012/09/13 15:58:11 sno Exp $

DISTNAME=	PadWalker-1.96
PKGNAME=	p5-${DISTNAME:S/96/9.6/}
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
