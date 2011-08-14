# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:32 obache Exp $
#

DISTNAME=		Proc-Wait3-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Proc-Wait3/
COMMENT=		Perl5 extension for wait3 system call
#LICENSE=

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/Wait3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
