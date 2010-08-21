# $NetBSD: Makefile,v 1.2 2010/08/21 16:34:20 seb Exp $
#

DISTNAME=		Proc-Wait3-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
