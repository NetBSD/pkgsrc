# $NetBSD: Makefile,v 1.1.1.1 2009/02/15 20:57:01 seb Exp $
#

DISTNAME=	Proc-Background-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Background/
COMMENT=	Perl 5 module prodiving an interface to background process management

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty

PERL5_PACKLIST=	auto/Proc/Background/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
