# $NetBSD: Makefile,v 1.19 2019/08/11 13:18:58 wiz Exp $

DISTNAME=	Carp-Assert-More-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Carp-Assert-More
COMMENT=	Perl5 module providing convenience wrappers around Carp::Assert
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Carp/Assert/More/.packlist

DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
