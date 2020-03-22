# $NetBSD: Makefile,v 1.29 2020/03/22 20:58:24 rillig Exp $

DISTNAME=		Proc-ProcessTable-0.59
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
