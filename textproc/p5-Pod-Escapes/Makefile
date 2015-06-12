# $NetBSD: Makefile,v 1.20 2015/06/12 10:51:26 wiz Exp $

DISTNAME=	Pod-Escapes-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Escapes/
COMMENT=	Perl module for decoding Pod E<...> sequences
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Pod/Escapes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
