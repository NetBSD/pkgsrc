# $NetBSD: Makefile,v 1.20 2004/03/26 02:27:37 wiz Exp $

DISTNAME=		doxygen-1.3.5.src
PKGNAME=		doxygen-1.3.5
PKGREVISION=		3
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
