# $NetBSD: Makefile,v 1.28 2011/08/14 12:26:12 obache Exp $
#

DISTNAME=	IO-stringy-2.110
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5isr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-stringy/
COMMENT=	Perl class for I/O on in-core objects like strings and arrays
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Stringy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
