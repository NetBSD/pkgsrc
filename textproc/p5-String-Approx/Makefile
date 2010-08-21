# $NetBSD: Makefile,v 1.12 2010/08/21 16:35:59 seb Exp $
#

DISTNAME=		String-Approx-3.26
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-Approx/
COMMENT=		Approximate (fuzzy) string matching library for Perl

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/String/Approx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
