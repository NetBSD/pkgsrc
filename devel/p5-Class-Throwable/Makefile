# $NetBSD: Makefile,v 1.1.1.1 2010/01/26 09:32:16 sno Exp $
#

DISTNAME=	Class-Throwable-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Throwable/
COMMENT=	Minimal lightweight exception class
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/Class/Throwable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
