# $NetBSD: Makefile,v 1.1.1.1 2006/08/09 08:03:33 jmmv Exp $

DISTNAME=	GMail-IMAPD-0.93
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GMail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~krs/GMail-IMAPD-0.93/
COMMENT=	IMAP gateway for the GMail web service

DEPENDS+=	p5-Crypt-SSLeay>=0.51:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-libwww>=5.80:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/GMail/IMAPD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
