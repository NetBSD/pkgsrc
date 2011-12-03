# $NetBSD: Makefile,v 1.9 2011/12/03 03:44:54 sbd Exp $
#

DISTNAME=	Search-Xapian-1.0.21.0
PKGNAME=	${DISTNAME:S/^/p5-/}
PKGREVISION=	2
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
