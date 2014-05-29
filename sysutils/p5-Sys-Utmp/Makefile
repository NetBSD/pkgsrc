# $NetBSD: Makefile,v 1.8 2014/05/29 23:37:31 wiz Exp $

DISTNAME=	Sys-Utmp-1.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-Utmp
COMMENT=	Object(ish) Interface to UTMP files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Sys/Utmp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
