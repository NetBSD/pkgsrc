# $NetBSD: Makefile,v 1.1.1.1 2001/09/04 21:05:06 groo Exp $

DISTNAME=		doxygen-1.2.10.src
PKGNAME=		doxygen-1.2.10
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://www.doxygen.org/
COMMENT=		documentation system for C++, Java, IDL and C

.if (defined(DOXYGEN_USE_TETEX) && \
    (${DOXYGEN_USE_TETEX} == yes || ${DOXYGEN_USE_TETEX} == YES))
DEPENDS+=		teTeX>=0.0:../../print/teTeX
.endif
.if (defined(DOXYGEN_USE_GHOSTSCRIPT) && \
    (${DOXYGEN_USE_GHOSTSCRIPT} == yes || ${DOXYGEN_USE_GHOSTSCRIPT} == YES))
DEPENDS+=		ghostscript>=0.0:../../print/ghostscript
.endif

USE_GMAKE=		yes
USE_PERL5=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--make ${GMAKE} --prefix ${LOCALBASE}

WRKSRC=			${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
