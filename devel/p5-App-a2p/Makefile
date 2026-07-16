# $NetBSD: Makefile,v 1.2 2026/07/16 19:01:52 wiz Exp $

DISTNAME=	App-a2p-1.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/App::a2p
COMMENT=	Awk to Perl translator
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/App/a2p/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
