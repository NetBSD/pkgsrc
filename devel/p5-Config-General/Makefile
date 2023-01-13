# $NetBSD: Makefile,v 1.49 2023/01/13 10:56:42 wen Exp $

DISTNAME=	Config-General-2.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.daemon.de/ConfigGeneral
COMMENT=	Perl Generic Config module
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
