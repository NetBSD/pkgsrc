# $NetBSD: Makefile,v 1.24 2014/05/29 23:35:25 wiz Exp $

DISTNAME=	mytop-1.6
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://jeremy.zawodny.com/mysql/mytop/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jeremy.zawodny.com/mysql/mytop/
COMMENT=	Console-based tool for monitoring the threads and performance of MySQL
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
#DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql

PERL5_PACKLIST=	auto/mytop/.packlist
REPLACE_PERL=	mytop
NO_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
