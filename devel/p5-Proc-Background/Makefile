# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:31 obache Exp $
#

DISTNAME=	Proc-Background-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Background/
COMMENT=	Perl 5 module prodiving an interface to background process management
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty

PERL5_PACKLIST=	auto/Proc/Background/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
