# $NetBSD: Makefile,v 1.20 2004/12/02 17:51:19 reed Exp $

DISTNAME=	libmng-1.0.8
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES= 	${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.3-t.com/libmng/download/ \
		http://www.libmng.com/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-lcms=${BUILDLINK_PREFIX.lcms}
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.lcms}

DOCDIR=			${PREFIX}/share/doc/mng

INSTALLATION_DIRS=	man/man3 man/man5

pre-configure:
	cd ${WRKSRC};				\
	${RM} -f configure.in && ${LN} -sf makefiles/configure.in .;	\
	${RM} -f Makefile.am && ${LN} -sf makefiles/Makefile.am .;	\
	${SETENV} AUTOM4TE=${LOCALBASE}/bin/autom4te ${ACLOCAL};	\
	${LOCALBASE}/bin/libtoolize --automake;	\
	${SETENV} AUTOCONF=${AUTOCONF} ${AUTOMAKE} -a --foreign -i;	\
	${AUTOCONF}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} Plan1.png Plan2.png libmng.txt ${DOCDIR}
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} libmng.3 ${PREFIX}/man/man3
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} jng.5 mng.5 ${PREFIX}/man/man5

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
