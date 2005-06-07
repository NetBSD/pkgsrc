# $NetBSD: Makefile,v 1.34 2005/06/07 14:14:48 markd Exp $

DISTNAME=	doxygen-1.4.3.src
PKGNAME=	doxygen-1.4.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.doxygen.org/
COMMENT=	Documentation system for C++, Java, IDL and C

DEPENDS+=	teTeX-[0-9]*:../../print/teTeX

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake perl flex
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--make ${GMAKE}
CONFIGURE_ARGS+=	--perl ${PERL5}
CONFIGURE_ARGS+=	--install ${INSTALL}
CONFIGURE_ARGS+=	--dot ${PREFIX}/bin/dot
CONFIGURE_ARGS+=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--docdir ${PREFIX}/share/doc
MAKE_ENV+=		PKGSRC_CFLAGS="${CFLAGS}"

SUBST_CLASSES+=		pybin
SUBST_STAGE.pybin=	pre-configure
SUBST_FILES.pybin=	doc/Makefile.in
SUBST_SED.pybin=	-e "s|@PYTHONBIN@|${PYTHONBIN}|g"

post-patch:
	${TOUCH} ${WRKSRC}/src/doxytag.l

post-install:
	cd ${WRKSRC} && ${GMAKE} install_docs

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
