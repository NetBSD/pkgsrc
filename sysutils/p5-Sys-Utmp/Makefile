# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:37 ryoon Exp $

DISTNAME=	Sys-Utmp-1.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-Utmp
COMMENT=	Object(ish) Interface to UTMP files

PERL5_PACKLIST=		auto/Sys/Utmp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
