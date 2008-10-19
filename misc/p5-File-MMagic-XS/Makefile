# $NetBSD: Makefile,v 1.2 2008/10/19 19:18:22 he Exp $

DISTNAME=		File-MMagic-XS-0.09003
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-MMagic/
COMMENT=		File Type With XS (a la mod_mime_magic)

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/MMagic/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
