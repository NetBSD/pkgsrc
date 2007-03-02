# $NetBSD: Makefile,v 1.1.1.1 2007/03/02 10:20:07 grant Exp $
#

DISTNAME=		Proc-Pidfile-1.005
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl module for maintaining a pid file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Proc/Pidfile/.packlist

DEPENDS+=		p5-Proc-ProcessTable>=0.41:../../devel/p5-Proc-ProcessTable

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
