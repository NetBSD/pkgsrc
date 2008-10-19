# $NetBSD: Makefile,v 1.4 2008/10/19 19:17:59 he Exp $
#

DISTNAME=	Smart-Comments-v1.0.3
PKGNAME=	p5-Smart-Comments-1.0.3
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Smart-Comments/
COMMENT=	Perl 5 module to insert debugging and tracking code easily

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Smart/Comments/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
