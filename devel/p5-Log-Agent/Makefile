# $NetBSD: Makefile,v 1.38 2024/11/16 12:04:30 wiz Exp $

DISTNAME=	Log-Agent-1.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Agent
COMMENT=	General logging framework aimed at reusable modules
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Log/Agent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
