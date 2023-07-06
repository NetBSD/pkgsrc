# $NetBSD: Makefile,v 1.19 2023/07/06 09:39:55 wiz Exp $
#

DISTNAME=		Proc-Wait3-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}
EXTRACT_USING=		gtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Proc-Wait3
COMMENT=		Perl5 extension for wait3 system call
LICENSE=		gnu-gpl-v1 AND artistic

PERL5_PACKLIST=		auto/Proc/Wait3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
