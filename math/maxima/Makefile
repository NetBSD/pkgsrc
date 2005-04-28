# $NetBSD: Makefile,v 1.1.1.1 2005/04/28 19:07:52 drochner Exp $
#

DISTNAME=		maxima-5.9.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system

DEPENDS+=		clisp-[0-9]*:../../lang/clisp
DEPENDS+=		tk-[0-9]*:../../x11/tk

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-clisp

.include "../../mk/bsd.pkg.mk"
