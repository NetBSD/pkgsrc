# $NetBSD: Makefile,v 1.20 2022/06/28 11:34:30 wiz Exp $

DISTNAME=	Mail-Webmail-Gmail-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-Webmail-Gmail
COMMENT=	Interface to Google's webmail service

DEPENDS+=	p5-Crypt-SSLeay>=0.51:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-libwww>=5.80:../../www/p5-libwww

PERL5_PACKLIST=	auto/Mail/Webmail/Gmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
