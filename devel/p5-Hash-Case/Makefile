# $NetBSD: Makefile,v 1.9 2011/08/14 12:26:08 obache Exp $
#

DISTNAME=	Hash-Case-1.01
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	2
SVR4_PKGNAME=	p5hac
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://perl.overmeer.net/perlws2003-hash/0-0/
HOMEPAGE=	http://search.cpan.org/dist/Hash-Case/
COMMENT=	Perl module that implements case-insensitive hashes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Report>=0.26:../../devel/p5-Log-Report

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Hash/Case/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
