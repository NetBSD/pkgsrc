# $NetBSD: Makefile,v 1.32 2021/09/18 13:55:25 wen Exp $

DISTNAME=		Proc-ProcessTable-0.62
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Proc-ProcessTable
COMMENT=		Perl extension to access the UNIX process table
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Proc/ProcessTable/.packlist

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
