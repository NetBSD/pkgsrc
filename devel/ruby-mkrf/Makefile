# $NetBSD: Makefile,v 1.3 2015/06/04 13:20:10 taca Exp $

DISTNAME=	mkrf-0.2.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mkrf.rubyforge.org/
COMMENT=	Library for generating Rakefiles
LICENSE=	mit

USE_RAKE=	RUN

SUBST_CLASSES+=		rake
SUBST_STAGE.rake=	pre-configure
SUBST_FILES.rake=	lib/mkrf/rakehelper.rb
SUBST_SED.rake=		-e "s|@RAKE@|${RAKE}|"
SUBST_MESSAGE.rake=	Fixate rake's path.

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
