# $NetBSD: Makefile,v 1.2 2012/10/03 21:57:08 wiz Exp $
#

DISTNAME=	Umph-Prompt-0.1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://umph.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/umph/
COMMENT=	Youtube feeds parsing module for umph
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Umph/Prompt/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
