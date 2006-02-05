# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:03 joerg Exp $
#

DISTNAME=		maxima-5.9.1
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system

DEPENDS+=		clisp-[0-9]*:../../lang/clisp
DEPENDS+=		tk-[0-9]*:../../x11/tk

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-clisp
USE_TOOLS+=		perl

.include "../../mk/bsd.pkg.mk"
