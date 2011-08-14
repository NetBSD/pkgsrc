# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:09 obache Exp $
#

DISTNAME=	IO-AIO-3.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-AIO/
COMMENT=	Perl 5 module implementing asynchronous input/output
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# Note: libeio is bundle with the distribution tarball.
# Its configure script is run via  Makefile.PL
# with all perl configuration settings, id est
# the Config module, set in its environment

PERL5_PACKLIST=	auto/IO/AIO/.packlist

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
