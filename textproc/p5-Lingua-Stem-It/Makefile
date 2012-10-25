# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:14 asau Exp $

DISTNAME=	Lingua-Stem-It-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-Stem-It/
COMMENT=	Porter's stemming algorithm for Italian
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Lingua/Stem/It/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
