# $NetBSD: Makefile,v 1.1.1.1 2009/12/06 15:38:47 seb Exp $

DISTNAME=	ORLite-Migrate-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AD/ADAMK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ORLite-Migrate/
COMMENT=	Perl 5 extremely light weight SQLite-specific schema migration
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBD-SQLite>=1.21:../../databases/p5-DBD-SQLite
# The minimum version required for PathTools is really 3.2701
DEPENDS+=	p5-PathTools>=3.29:../../devel/p5-PathTools
DEPENDS+=	p5-File-pushd>=1.00:../../devel/p5-File-pushd
DEPENDS+=	p5-IPC-Run3>=0.042:../../devel/p5-IPC-Run3
DEPENDS+=	p5-ORLite>=1.28:../../databases/p5-ORLite
DEPENDS+=	p5-Params-Util>=0.37:../../devel/p5-Params-Util
DEPENDS+=	p5-Probe-Perl>=0.01:../../devel/p5-Probe-Perl

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.58

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/ORLite/Migrate/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
