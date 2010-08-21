# $NetBSD: Makefile,v 1.18 2010/08/21 16:35:45 seb Exp $
#

DISTNAME=		SHA-2.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5sha
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=SHA/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 interface to the SHA1 algorithm

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
