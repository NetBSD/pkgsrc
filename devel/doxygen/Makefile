# $NetBSD: Makefile,v 1.2 2001/09/04 22:05:49 groo Exp $

DISTNAME=		doxygen-1.2.10.src
PKGNAME=		doxygen-1.2.10
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://www.doxygen.org/
COMMENT=		documentation system for C++, Java, IDL and C

DEPENDS+=		teTeX>=0.0:../../print/teTeX
DEPENDS+=		ghostscript>=0.0:../../print/ghostscript

USE_GMAKE=		yes
USE_PERL5=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--make ${GMAKE} --prefix ${LOCALBASE}
CONFIGURE_ARGS+=	--docdir ${LOCALBASE}/share/doc

WRKSRC=			${WRKDIR}/${PKGNAME}

post-install:
	cd ${WRKSRC}; ${GMAKE} install_docs

.include "../../mk/bsd.pkg.mk"
