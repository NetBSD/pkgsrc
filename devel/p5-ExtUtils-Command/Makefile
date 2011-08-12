# $NetBSD: Makefile,v 1.6 2011/08/12 12:44:03 adam Exp $

DISTNAME=	ExtUtils-Command-1.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Command/
COMMENT=	Perl 5 functions to replace common UNIX commands in Makefiles
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/Command/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
