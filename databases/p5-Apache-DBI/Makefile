# $NetBSD: Makefile,v 1.16 2007/02/18 01:59:36 wiz Exp $
#

DISTNAME=	Apache-DBI-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5adb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-DBI/
COMMENT=	DBI support for Apache+mod_perl

DEPENDS+=	p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=	p5-Digest-SHA1>=2.01:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Test-Simple>=0.47:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Apache/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
