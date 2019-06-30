# $NetBSD: Makefile,v 1.12 2019/06/30 20:16:51 nia Exp $

DISTNAME=	Lingua-Stem-It-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-Stem-It
COMMENT=	Porter's stemming algorithm for Italian
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Lingua/Stem/It/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
