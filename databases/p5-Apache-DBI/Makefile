# $NetBSD: Makefile,v 1.12 2005/12/18 18:06:12 wiz Exp $
#

DISTNAME=	Apache-DBI-0.94
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5adb
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-DBI/
COMMENT=	DBI support for Apache+mod_perl

DEPENDS+=	p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=	p5-Test-Simple>=0.47:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Apache/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
