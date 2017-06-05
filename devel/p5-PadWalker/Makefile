# $NetBSD: Makefile,v 1.17 2017/06/05 14:23:26 ryoon Exp $

DISTNAME=	PadWalker-2.2
PKGNAME=	p5-${DISTNAME:S/96/9.6/}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RO/ROBIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PadWalker/
COMMENT=	Play with other peoples' lexical variables
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/PadWalker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
