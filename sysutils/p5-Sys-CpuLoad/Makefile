# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:46 joerg Exp $

DISTNAME=	Sys-CpuLoad-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-CpuLoad
COMMENT=	Module to retrieve system load averages

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Sys/CpuLoad/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
