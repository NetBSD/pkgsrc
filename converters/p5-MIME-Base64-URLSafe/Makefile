# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:42 he Exp $
#

DISTNAME=		MIME-Base64-URLSafe-0.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MIME-Base64-URLSafe/
COMMENT=		Perl version of Python's URL-safe base64 codec

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MIME/Base64/URLSafe/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
