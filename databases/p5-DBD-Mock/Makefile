# $NetBSD: Makefile,v 1.1.1.1 2009/01/11 13:50:20 he Exp $
#

DISTNAME=	DBD-Mock-1.39
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ddm
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-Mock/
COMMENT=	Perl5 module with mock database driver for testing

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DBI>=1.3:../../databases/p5-DBI

PERL5_PACKLIST=	auto/DBD/Mock/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
