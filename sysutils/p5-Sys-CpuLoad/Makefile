# $NetBSD: Makefile,v 1.15 2017/06/05 14:24:37 ryoon Exp $

DISTNAME=	Sys-CpuLoad-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-CpuLoad
COMMENT=	Module to retrieve system load averages
LICENSE=	gnu-gpl-v2 OR artistic

PERL5_PACKLIST=		auto/Sys/CpuLoad/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
