# $NetBSD: Makefile,v 1.15 2005/02/19 19:09:38 wiz Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Iconv/.packlist

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/perl5/module.mk"
# if this line is too high up and BUILDLINK_LDADD.iconv
# is empty, LIBS will be set to the following argument in
# MAKE_PARAMS
MAKE_PARAMS+=		LIBS=${BUILDLINK_LDADD.iconv}
.include "../../mk/bsd.pkg.mk"
