# $NetBSD: Makefile,v 1.8 2002/12/14 03:43:18 schmonz Exp $

DISTNAME=		doxygen-1.2.18.src
PKGNAME=		doxygen-1.2.18
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://www.doxygen.org/
COMMENT=		Documentation system for C++, Java, IDL and C

DEPENDS+=		teTeX>=0.0:../../print/teTeX

USE_GMAKE=		yes
USE_PERL5=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--make ${GMAKE}
CONFIGURE_ARGS+=	--install ${INSTALL}
CONFIGURE_ARGS+=	--prefix ${LOCALBASE}
CONFIGURE_ARGS+=	--docdir ${LOCALBASE}/share/doc
REPLACE_PERL=		doc/translater.pl

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

post-install:
	cd ${WRKSRC} && ${GMAKE} install_docs

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
