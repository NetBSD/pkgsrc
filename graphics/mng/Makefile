# $NetBSD: Makefile,v 1.10 2003/03/04 13:50:16 wiz Exp $

DISTNAME=	libmng-1.0.5
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-lcms=${BUILDLINK_PREFIX.lcms}
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.lcms}

DOCDIR=			${PREFIX}/share/doc/mng

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} Plan1.png Plan2.png libmng.txt ${DOCDIR}
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} libmng.3 ${PREFIX}/man/man3
	cd ${WRKSRC}/doc/man && \
		${INSTALL_MAN} jng.5 mng.5 ${PREFIX}/man/man5

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/lcms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
