# $NetBSD: Makefile,v 1.3 2007/02/22 19:26:23 wiz Exp $
#

DISTNAME=	Hash-Case-1.003
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hac
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/perlws2003-hash/0-0/
COMMENT=	Perl module that implements case-insensitive hashes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Hash/Case/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
