# $NetBSD: Makefile,v 1.5 2002/06/17 16:40:26 agc Exp $

DISTNAME=		doxygen-1.2.10.src
PKGNAME=		doxygen-1.2.10
PKGREVISION=		2
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
REPLACE_PERL=		${WRKSRC}/doc/translater.pl

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

post-install:
	cd ${WRKSRC}; ${GMAKE} install_docs

.include "../../mk/bsd.pkg.mk"
