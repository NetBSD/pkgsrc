# $NetBSD: Makefile,v 1.9 2011/08/14 08:18:09 obache Exp $

DISTNAME=	ORLite-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AD/ADAMK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ORLite/
COMMENT=	Perl 5 extremely light weight SQLite-specific ORM
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Script>=1.06:../../devel/p5-Test-Script

DEPENDS+=	p5-DBD-SQLite>=1.27:../../databases/p5-DBD-SQLite
DEPENDS+=	{perl>=5.10.1,p5-File-Path>=2.04}:../../devel/p5-File-Path
DEPENDS+=	p5-File-Remove>=1.40:../../sysutils/p5-File-Remove
DEPENDS+=	{perl>=5.10.1,p5-File-Temp>=0.20}:../../devel/p5-File-Temp
DEPENDS+=	p5-Params-Util>=0.33:../../devel/p5-Params-Util

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.607

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/ORLite/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
