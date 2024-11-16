# $NetBSD: Makefile,v 1.22 2024/11/16 12:06:40 wiz Exp $

DISTNAME=	Sys-Utmp-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sys-Utmp
COMMENT=	Object(ish) Interface to UTMP files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Sys/Utmp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
