# $NetBSD: Makefile,v 1.5 2002/10/09 17:35:57 wiz Exp $
#

DISTNAME=	Text-Iconv-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5tic
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.linguistik.uni-erlangen.de/~mxp/
COMMENT=	Perl interface to iconv() codeset conversion function

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Iconv/.packlist

.include "../../converters/libiconv/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
