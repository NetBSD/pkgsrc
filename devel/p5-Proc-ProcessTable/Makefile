# $NetBSD: Makefile,v 1.38 2025/07/04 08:46:30 wiz Exp $

DISTNAME=		Proc-ProcessTable-0.636
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
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
