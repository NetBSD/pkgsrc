# $NetBSD: Makefile,v 1.14 2012/10/03 21:57:58 wiz Exp $
#

DISTNAME=		String-Approx-3.26
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-Approx/
COMMENT=		Approximate (fuzzy) string matching library for Perl

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/String/Approx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
