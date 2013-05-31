# $NetBSD: Makefile,v 1.8 2013/05/31 12:41:28 wiz Exp $

DISTNAME=		File-MMagic-XS-0.09006
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-MMagic/
COMMENT=		File Type With XS (a la mod_mime_magic)
LICENSE=		${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

PERL5_PACKLIST=		auto/File/MMagic/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
