# $NetBSD: Makefile,v 1.1 2015/09/06 20:40:49 wiz Exp $

DISTNAME=	File-Slurper-0.008
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Slurper/
COMMENT=	Simple, sane and efficient module to slurp a file
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
