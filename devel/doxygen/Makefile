# $NetBSD: Makefile,v 1.24 2004/10/03 00:13:26 tv Exp $

DISTNAME=		doxygen-1.3.8.src
PKGNAME=		doxygen-1.3.8
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=		groo@NetBSD.org
HOMEPAGE=		http://www.doxygen.org/
COMMENT=		Documentation system for C++, Java, IDL and C

DEPENDS+=		teTeX-[0-9]*:../../print/teTeX

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_PERL5=		yes
USE_BUILDLINK3=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--make ${GMAKE}
CONFIGURE_ARGS+=	--perl ${PERL5}
CONFIGURE_ARGS+=	--install ${INSTALL}
CONFIGURE_ARGS+=	--dot ${PREFIX}/bin/dot
CONFIGURE_ARGS+=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--docdir ${PREFIX}/share/doc

SUBST_CLASSES+=		pybin
SUBST_STAGE.pybin=	pre-configure
SUBST_FILES.pybin=	doc/Makefile.in
SUBST_SED.pybin=	-e "s|@PYTHONBIN@|${PYTHONBIN}|g"

post-install:
	cd ${WRKSRC} && ${GMAKE} install_docs

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
