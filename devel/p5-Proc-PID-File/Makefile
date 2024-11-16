# $NetBSD: Makefile,v 1.24 2024/11/16 12:04:58 wiz Exp $

DISTNAME=		Proc-PID-File-1.29
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Proc-PID-File
COMMENT=		Perl module to manage process-ID files
LICENSE=		gnu-gpl-v2

PERL5_PACKLIST=		auto/Proc/PID/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
