# $NetBSD: Makefile,v 1.1.1.1 2012/05/16 15:55:23 bouyer Exp $

DISTNAME=	AuthCAS-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OS/OSALAUN/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~osalaun/AuthCAS-1.5/
COMMENT=	AuthCAS - Client library for CAS 2.0 authentication server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		#

PERL5_PACKLIST= ${PERL5_ARCHLIB}auto/AuthCAS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
