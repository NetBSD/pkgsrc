# $NetBSD: Makefile,v 1.19 2004/01/22 08:24:29 grant Exp $

DISTNAME=		doxygen-1.3.5.src
PKGNAME=		doxygen-1.3.5
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=		groo@NetBSD.org
HOMEPAGE=		http://www.doxygen.org/
COMMENT=		Documentation system for C++, Java, IDL and C

DEPENDS+=		teTeX-[0-9]*:../../print/teTeX

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_GNU_TOOLS+=		make
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
