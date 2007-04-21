# $NetBSD: Makefile,v 1.1.1.1 2007/04/21 15:00:52 heinz Exp $

DISTNAME=		Email-MIME-Encodings-1.311
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5eme
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/dist/Email-MIME-Encodings/
COMMENT=		Unified interface to MIME encoding and decoding

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-MIME-Base64>=3.05:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Email/MIME/Encodings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
