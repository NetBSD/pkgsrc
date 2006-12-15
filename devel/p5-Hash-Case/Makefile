# $NetBSD: Makefile,v 1.2 2006/12/15 14:34:20 wiz Exp $
#

DISTNAME=      	Hash-Case-1.003
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
