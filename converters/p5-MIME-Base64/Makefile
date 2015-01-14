# $NetBSD: Makefile,v 1.53 2015/01/14 13:12:09 wiz Exp $

DISTNAME=	MIME-Base64-3.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Base64/
COMMENT=	Perl5 module for Base64 and Quoted-Printable encodings
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MIME/Base64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
