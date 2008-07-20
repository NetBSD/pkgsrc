# $NetBSD: Makefile,v 1.5 2008/07/20 21:47:40 he Exp $
#

DISTNAME=	Hash-Case-1.006
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hac
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/perlws2003-hash/0-0/
HOMEPAGE+=	http://search.cpan.org/dist/Hash-Case/
COMMENT=	Perl module that implements case-insensitive hashes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Hash/Case/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
