# $NetBSD: Makefile,v 1.4 2009/07/07 16:31:42 sno Exp $
#

DISTNAME=	Search-Xapian-1.0.13.1
PKGNAME=	${DISTNAME:S/^/p5-/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://xapian.org/docs/bindings/perl/Search/Xapian.html
COMMENT=	Perl XS frontend to the Xapian C++ search library
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

PERL5_PACKLIST=	auto/Search/Xapian/.packlist

.include "../../textproc/xapian/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
