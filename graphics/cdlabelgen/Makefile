# $NetBSD: Makefile,v 1.6 2002/06/04 06:50:44 tron Exp $

DISTNAME=		cdlabelgen-1.5.0
CATEGORIES=		graphics
MASTER_SITES=		http://www.red-bean.com/fitz/software/cdlabelgen/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.red-bean.com/~bwf/software/cdlabelgen/
COMMENT=		generate frontcards and traycards for CDs

USE_PERL5=		YES
MAKE_ENV+=		SED="${SED}" MV="${MV}"
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=		INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}"

.include "../../mk/bsd.pkg.mk"
