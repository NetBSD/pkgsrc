# $NetBSD: Makefile,v 1.13 2004/12/20 11:30:56 grant Exp $
#

DISTNAME=	Text-Iconv-1.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tic
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Iconv/
COMMENT=	Perl interface to iconv() codeset conversion function

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Iconv/.packlist
MAKE_PARAMS=		LIBS=${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
