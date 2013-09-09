# $NetBSD: Makefile,v 1.4 2013/09/09 12:29:25 fhajny Exp $

DISTNAME=	locale-2.0.8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Pure ruby library which provides basic APIs for localization
LICENSE=	ruby-license OR gnu-lgpl-v3

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
