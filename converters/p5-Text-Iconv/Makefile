# $NetBSD: Makefile,v 1.21 2008/10/19 19:17:42 he Exp $
#

DISTNAME=	Text-Iconv-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5tic
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Iconv/
COMMENT=	Perl interface to iconv() codeset conversion function

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Iconv/.packlist

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
