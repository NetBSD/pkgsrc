# $NetBSD: Makefile,v 1.4 2012/10/02 21:25:26 asau Exp $

DISTNAME=	DBD-DB2-1.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-DB2/
COMMENT=	Perl DBI/DBD driver for DB2 databases
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/DBD/DB2/.packlist

.include "../../mk/bsd.prefs.mk"

.if !defined(DB2_HOME)
PKG_FAIL_REASON+=	"You must set DB2_HOME to the location of your DB2 installation"
.elif !exists(${DB2_HOME})
PKG_FAIL_REASON+=	"The location of DB2_HOME does not exist"
.endif

BUILDLINK_PASSTHRU_DIRS+=	${DB2_HOME}

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
