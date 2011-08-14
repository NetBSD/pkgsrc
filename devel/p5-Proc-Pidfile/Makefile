# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:32 obache Exp $
#

DISTNAME=		Proc-Pidfile-1.005
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl module for maintaining a pid file

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/Pidfile/.packlist

DEPENDS+=		p5-Proc-ProcessTable>=0.41:../../devel/p5-Proc-ProcessTable

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
