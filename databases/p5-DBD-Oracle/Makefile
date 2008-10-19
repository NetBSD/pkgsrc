# $NetBSD: Makefile,v 1.11 2008/10/19 19:17:44 he Exp $

DISTNAME=	DBD-Oracle-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl DBI/DBD driver for Oracle databases

PERL5_PACKLIST=	auto/DBD/Oracle/.packlist

.include "../../mk/bsd.prefs.mk"

.if !defined(ORACLE_HOME)
PKG_FAIL_REASON+=	"You must set ORACLE_HOME to the location of your Oracle installation"
.elif !exists(${ORACLE_HOME})
PKG_FAIL_REASON+=	"The location of ORACLE_HOME does not exist"
.endif

BUILDLINK_PASSTHRU_DIRS+=	${ORACLE_HOME}

LDFLAGS+=	-L${ORACLE_HOME}/lib
LDFLAGS+=	${COMPILER_RPATH_FLAG}${ORACLE_HOME}/lib
LDFLAGS+=	-lclntsh

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
