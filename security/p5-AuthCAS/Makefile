# $NetBSD: Makefile,v 1.4.2.2 2012/05/21 13:51:34 tron Exp $

DISTNAME=	AuthCAS-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OS/OSALAUN/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AuthCAS/
COMMENT=	AuthCAS - Client library for CAS 2.0 authentication server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/AuthCAS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
