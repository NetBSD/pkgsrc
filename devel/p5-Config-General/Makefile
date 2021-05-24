# $NetBSD: Makefile,v 1.46 2021/05/24 19:50:21 wiz Exp $

DISTNAME=	Config-General-2.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.daemon.de/ConfigGeneral
COMMENT=	Perl Generic Config module
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
