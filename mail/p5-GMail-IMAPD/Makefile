# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:24 joerg Exp $

DISTNAME=	GMail-IMAPD-0.93
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GMail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~krs/GMail-IMAPD-0.93/
COMMENT=	IMAP gateway for the GMail web service

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Crypt-SSLeay>=0.51:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-libwww>=5.80:../../www/p5-libwww

PERL5_PACKLIST=	auto/GMail/IMAPD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
