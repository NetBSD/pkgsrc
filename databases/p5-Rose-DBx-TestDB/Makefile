# $NetBSD: Makefile,v 1.5 2011/08/14 08:18:10 obache Exp $

DISTNAME=	Rose-DBx-TestDB-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Rose::DBx::TestDB
COMMENT=	Test Rose::DB::Object modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBD-SQLite>=1.08:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Rose-DB-[0-9]*:../../databases/p5-Rose-DB
DEPENDS+=	{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Rose/DBx/TestDB/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
