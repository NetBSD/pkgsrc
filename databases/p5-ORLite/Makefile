# $NetBSD: Makefile,v 1.1.1.1 2009/12/06 13:48:25 seb Exp $

DISTNAME=	ORLite-1.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AD/ADAMK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ORLite/
COMMENT=	Perl 5 extremely light weight SQLite-specific ORM
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Script>=1.06:../../devel/p5-Test-Script
DEPENDS+=	p5-DBD-SQLite>=1.25:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-File-Remove>=1.40:../../sysutils/p5-File-Remove
DEPENDS+=	p5-File-Temp>=0.20:../../devel/p5-File-Temp
DEPENDS+=	p5-Params-Util>=0.33:../../devel/p5-Params-Util

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/ORLite/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
