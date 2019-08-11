# $NetBSD: Makefile,v 1.28 2019/08/11 13:18:24 wiz Exp $

DISTNAME=	DBD-Oracle-1.74
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-Oracle
COMMENT=	Perl DBI/DBD driver for Oracle databases
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/DBD/Oracle/.packlist

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-DBD-Oracle

PKG_SUPPORTED_OPTIONS=	# empty
PKG_SUGGESTED_OPTIONS=	# empty

PKG_OPTIONS_REQUIRED_GROUPS=	oralib
PKG_OPTIONS_GROUP.oralib=	lib32 libsys libbase
PKG_SUGGESTED_OPTIONS=		libsys

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !defined(ORACLE_HOME)
PKG_FAIL_REASON+=	"You must set ORACLE_HOME to the location of your Oracle installation"
.elif !exists(${ORACLE_HOME})
PKG_FAIL_REASON+=	"The location of ORACLE_HOME does not exist"
.endif

BUILDLINK_PASSTHRU_DIRS+=	${ORACLE_HOME}

.if !empty(PKG_OPTIONS:Mlib32)
LDFLAGS+=	-L${ORACLE_HOME}/lib32
LDFLAGS+=	${COMPILER_RPATH_FLAG}${ORACLE_HOME}/lib32
.elif !empty(PKG_OPTIONS:Mlibsys)
LDFLAGS+=	-L${ORACLE_HOME}/lib
LDFLAGS+=	${COMPILER_RPATH_FLAG}${ORACLE_HOME}/lib
.elif !empty(PKG_OPTIONS:Mlibbase)
LDFLAGS+=	-L${ORACLE_HOME}
LDFLAGS+=	${COMPILER_RPATH_FLAG}${ORACLE_HOME}
.endif

CFLAGS+=	-I${ORACLE_HOME}/rdbms/public/
LDFLAGS+=	-lclntsh

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
