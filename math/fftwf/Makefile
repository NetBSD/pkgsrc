# $NetBSD: Makefile,v 1.28 2020/08/31 18:10:11 wiz Exp $

PKGREVISION= 2
.include "../../math/fftw/Makefile.common"

PKGNAME=	${DISTNAME:C/fftw/fftwf/}

COMMENT=	Collection of fast C routines to compute DFTs

CONFIGURE_ARGS+=	--enable-single

.if ${MACHINE_ARCH} == "i386"
#CONFIGURE_ARGS+=	--enable-sse
CONFIGURE_ARGS+=	--with-our-malloc16
.endif

.include "../../math/fftw/options.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1
INSTALL_TARGET=		install-libLTLIBRARIES install-pkgconfigDATA

post-install:
.if ${PTHREAD_TYPE} == "native"
	cd ${WRKSRC}/threads &&						\
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV} 				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
		install-libLTLIBRARIES
.endif
	cd ${WRKSRC}/tools &&						\
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV} 				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
		install-binPROGRAMS
	${INSTALL_MAN} ${WRKSRC}/tools/fftwf-wisdom.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
