# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 08:43:20 abs Exp $

DISTNAME=	Rose-DBx-TestDB-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Rose::DBx::TestDB
COMMENT=	Test Rose::DB::Object modules

DEPENDS+=	p5-DBD-SQLite>=0:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Rose-DB>=0:../../databases/p5-Rose-DB
DEPENDS+=	p5-File-Temp>=0:../../devel/p5-File-Temp

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Rose/DBx/TestDB/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
