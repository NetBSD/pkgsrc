# $NetBSD: Makefile,v 1.15 2006/11/05 17:35:58 joerg Exp $
#

DISTNAME=		Digest-HMAC-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hmac
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-HMAC/
COMMENT=		Perl5 module for HMAC

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Digest-SHA1>=1.00:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5>=2.00:../../security/p5-Digest-MD5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Digest/HMAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
