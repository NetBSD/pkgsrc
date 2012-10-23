# $NetBSD: Makefile,v 1.6 2012/10/23 18:16:39 asau Exp $

DISTNAME=	AuthCAS-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OS/OSALAUN/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AuthCAS/
COMMENT=	AuthCAS - Client library for CAS 2.0 authentication server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/AuthCAS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
