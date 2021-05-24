# $NetBSD: Makefile,v 1.25 2021/05/24 19:51:20 wiz Exp $

DISTNAME=	PadWalker-2.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RO/ROBIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PadWalker
COMMENT=	Play with other peoples' lexical variables
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/PadWalker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
