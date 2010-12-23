# $NetBSD: Makefile,v 1.36 2010/12/23 11:44:43 dsainty Exp $

DISTNAME=	libmng-1.0.10
PKGNAME=	mng-1.0.10
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

PKG_DESTDIR_SUPPORT=	user-destdir

# Waiting for automake to be pkgviews-enabled
#PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		automake

CONFIGURE_ARGS+=	--with-jpeg=${JPEGBASE}
CONFIGURE_ARGS+=	--with-lcms=${BUILDLINK_PREFIX.lcms}
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.lcms}

DOCDIR=			${PREFIX}/share/doc/mng

INSTALLATION_DIRS=	${PKGMANDIR}/man3 ${PKGMANDIR}/man5 ${DOCDIR}

pre-configure:
	cd ${WRKSRC};							\
	${RM} -f configure.in && ${LN} -sf makefiles/configure.in .;	\
	${RM} -f Makefile.am && ${LN} -sf makefiles/Makefile.am .;	\
	aclocal;							\
	${LOCALBASE}/bin/libtoolize --automake;				\
	automake -a --foreign -i;					\
	autoconf

post-install:
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} Plan1.png Plan2.png libmng.txt ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} libmng.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} jng.5 mng.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
