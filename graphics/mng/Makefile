# $NetBSD: Makefile,v 1.27 2006/01/20 23:41:30 jlam Exp $

DISTNAME=	lm1009
PKGNAME=	mng-1.0.9
CATEGORIES=	graphics
MASTER_SITES= 	${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.3-t.com/libmng/download/ \
		http://www.libmng.com/download/
# this is just a workaround because the 1.0.9 tar.gz is broken
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

# Waiting for automake to be pkgviews-enabled
#PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		automake

# only needed as long as we use the zip distfile
EXTRACT_OPTS_ZIP?=  	-aqo
WRKSRC=			${WRKDIR}/libmng

CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-lcms=${BUILDLINK_PREFIX.lcms}
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.lcms}

DOCDIR=			${PREFIX}/share/doc/mng

INSTALLATION_DIRS=	${PKGMANDIR}/man3 ${PKGMANDIR}/man5

pre-configure:
	cd ${WRKSRC};							\
	${RM} -f configure.in && ${LN} -sf makefiles/configure.in .;	\
	${RM} -f Makefile.am && ${LN} -sf makefiles/Makefile.am .;	\
	aclocal;							\
	${LOCALBASE}/bin/libtoolize --automake;				\
	automake -a --foreign -i;					\
	autoconf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} Plan1.png Plan2.png libmng.txt ${DOCDIR}
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} libmng.3 ${PREFIX}/${PKGMANDIR}/man3
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} jng.5 mng.5 ${PREFIX}/${PKGMANDIR}/man5

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
