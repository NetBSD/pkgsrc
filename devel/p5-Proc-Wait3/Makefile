# $NetBSD: Makefile,v 1.11 2016/07/27 00:17:37 wen Exp $
#

DISTNAME=		Proc-Wait3-0.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}
EXTRACT_USING=		gtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Proc-Wait3/
COMMENT=		Perl5 extension for wait3 system call
LICENSE=		gnu-gpl-v1 AND artistic

PERL5_PACKLIST=		auto/Proc/Wait3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
