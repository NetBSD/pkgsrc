# $NetBSD: Makefile,v 1.26 2004/01/05 22:16:24 jlam Exp $
#

VER=		1.22
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
SVR4_PKGNAME=	p5dpo
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/dbdpg/projdisplay.php
COMMENT=	Perl DBI/DBD driver for PostgreSQL databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/Pg/.packlist

PGUSER?=	pgsql
PGPREFIX=	${PREFIX}/${PGUSER}

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
