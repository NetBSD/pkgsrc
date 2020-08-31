# $NetBSD: Makefile,v 1.20 2020/08/31 18:11:33 wiz Exp $

DISTNAME=	Sys-CpuLoad-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sys-CpuLoad
COMMENT=	Module to retrieve system load averages
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/Sys/CpuLoad/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
