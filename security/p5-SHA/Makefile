# $NetBSD: Makefile,v 1.21 2011/08/14 14:42:51 obache Exp $
#

DISTNAME=		SHA-2.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
SVR4_PKGNAME=		p5sha
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=SHA/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/SHA/
COMMENT=		Perl5 interface to the SHA1 algorithm

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Digest-SHA1>=1.0:../../security/p5-Digest-SHA1

PERL5_PACKLIST=		auto/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
