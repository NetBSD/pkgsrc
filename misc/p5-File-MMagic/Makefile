# $NetBSD: Makefile,v 1.19 2008/10/19 19:18:22 he Exp $

DISTNAME=		File-MMagic-1.27
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5fim
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-MMagic/
COMMENT=		Perl5 module to guess file types

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/MMagic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
