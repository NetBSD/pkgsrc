# $NetBSD: Makefile,v 1.16 2003/12/23 21:10:22 jmmv Exp $

DISTNAME=		doxygen-1.3.5.src
PKGNAME=		doxygen-1.3.5
PKGREVISION=		1
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=		groo@NetBSD.org
HOMEPAGE=		http://www.doxygen.org/
COMMENT=		Documentation system for C++, Java, IDL and C

DEPENDS+=		{teTeX-[0-9]*,teTeX2-[0-9]*}:../../print/teTeX2

USE_GMAKE=		yes
USE_PERL5=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--make ${GMAKE}
CONFIGURE_ARGS+=	--install ${INSTALL}
CONFIGURE_ARGS+=	--prefix ${LOCALBASE}
CONFIGURE_ARGS+=	--docdir ${LOCALBASE}/share/doc
REPLACE_PERL=		doc/translater.pl

post-install:
	cd ${WRKSRC} && ${GMAKE} install_docs

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
