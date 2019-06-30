# $NetBSD: Makefile,v 1.17 2019/06/30 20:16:46 nia Exp $

DISTNAME=	Sys-CpuLoad-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sys-CpuLoad
COMMENT=	Module to retrieve system load averages
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/Sys/CpuLoad/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
