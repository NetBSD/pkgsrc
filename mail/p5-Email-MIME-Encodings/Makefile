# $NetBSD: Makefile,v 1.7 2011/08/14 13:25:23 obache Exp $

DISTNAME=		Email-MIME-Encodings-1.313
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5eme
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-MIME-Encodings/
COMMENT=		Unified interface to MIME encoding and decoding
LICENSE=		artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-MIME-Base64>=3.05:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Email/MIME/Encodings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
