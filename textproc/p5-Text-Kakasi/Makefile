# $NetBSD: Makefile,v 1.17 2009/05/21 12:32:05 sno Exp $

DISTNAME=		Text-Kakasi-2.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tka
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Kakasi/
COMMENT=		Perl5 module to use Kakasi
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Kakasi/.packlist

.include "../../textproc/kakasi/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
