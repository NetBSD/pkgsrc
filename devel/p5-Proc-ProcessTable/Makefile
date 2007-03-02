# $NetBSD: Makefile,v 1.1.1.1 2007/03/02 10:18:06 grant Exp $
#

DISTNAME=		Proc-ProcessTable-0.41
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl extension to access the UNIX process table

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Proc/ProcessTable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
