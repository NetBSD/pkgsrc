# $NetBSD: Makefile,v 1.9 2011/08/14 12:26:39 obache Exp $

DISTNAME=	Term-Size-0.207
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Size/
COMMENT=	Perl extension for retrieving terminal size
LICENSE=	gnu-gpl-v2 OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Term/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
