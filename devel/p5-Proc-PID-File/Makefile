# $NetBSD: Makefile,v 1.15 2017/06/05 14:23:30 ryoon Exp $
#

DISTNAME=		Proc-PID-File-1.28
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Proc-PID-File/
COMMENT=		Perl module to manage process-ID files
LICENSE=		gnu-gpl-v2

PERL5_PACKLIST=		auto/Proc/PID/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
