# $NetBSD: Makefile,v 1.17 2005/04/11 21:45:09 tv Exp $
#

DISTNAME=	Text-Iconv-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5tic
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Iconv/
COMMENT=	Perl interface to iconv() codeset conversion function

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Iconv/.packlist

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
