# $NetBSD: Makefile,v 1.1.1.1 2006/08/09 07:59:11 jmmv Exp $

DISTNAME=	Mail-Webmail-Gmail-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mincus/Mail-Webmail-Gmail-1.08/
COMMENT=	Interface to Google's webmail service

DEPENDS+=	p5-Crypt-SSLeay>=0.51:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-libwww>=5.80:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Mail/Webmail/Gmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
