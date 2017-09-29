# $NetBSD: Makefile,v 1.14 2017/09/29 21:54:49 wiz Exp $

DISTNAME=	Sys-Utmp-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-Utmp
COMMENT=	Object(ish) Interface to UTMP files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Sys/Utmp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
