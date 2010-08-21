# $NetBSD: Makefile,v 1.5 2010/08/21 16:35:11 seb Exp $

DISTNAME=	Math-Base85-0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension for base 85 numbers, as referenced by RFC 1924

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/Base85/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
