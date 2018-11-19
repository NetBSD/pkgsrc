# $NetBSD: Makefile,v 1.1 2018/11/19 12:48:06 tnn Exp $

DISTNAME=	BackupPC-XS-0.57
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CB/CBARRATT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/backuppc/backuppc-xs
COMMENT=	Perl utility functions for sysutils/backuppc
LICENSE=	gnu-gpl-v3

PERL5_PACKLIST=		auto/BackupPC/XS/.packlist
PERL5_MODULE_TYPE=	MakeMaker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
