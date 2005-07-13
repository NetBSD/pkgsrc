# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:20 jlam Exp $

DISTNAME=	DBD-Oracle-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl DBI/DBD driver for Oracle databases

PERL5_PACKLIST=	auto/DBD/Oracle/.packlist

.if !defined(ORACLE_HOME)
PKG_SKIP_REASON+=	"You must set ORACLE_HOME to the location of your Oracle installation"
.elif !exists(${ORACLE_HOME})
PKG_FAIL_REASON+=	"The location of ORACLE_HOME does not exist"
.endif

BUILDLINK_PASSTHRU_DIRS+=	${ORACLE_HOME}

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
