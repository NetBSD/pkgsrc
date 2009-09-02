# $NetBSD: Makefile,v 1.20 2009/09/02 08:34:14 wiz Exp $

DISTNAME=		File-MMagic-1.27
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5fim
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-MMagic/
COMMENT=		Perl5 module to guess file types

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/MMagic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
