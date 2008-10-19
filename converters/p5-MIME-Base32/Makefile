# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:42 he Exp $
#

VERS=			1.01
DISTNAME=		MIME-Base32-${VERS}
PKGNAME=		p5-MIME-Base32-${VERS}
PKGREVISION=		1
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MIME-Base32/
COMMENT=		Perl5 module for Base32 encoding

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MIME/Base32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
