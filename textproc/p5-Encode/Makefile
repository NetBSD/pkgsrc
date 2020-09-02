# $NetBSD: Makefile,v 1.55 2020/09/02 13:15:09 otis Exp $

DISTNAME=	Encode-3.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Encode
COMMENT=	Provides interfaces between strings and the rest of the system
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
