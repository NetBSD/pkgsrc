# $NetBSD: Makefile,v 1.1 1998/06/03 21:04:00 tv Exp $
#

DISTNAME=	egcs-19980531
CATEGORIES=	lang
MASTER_SITES=	ftp://egcs.cygnus.com/pub/egcs/snapshots/1998-05-31/

MAINTAINER=	tv@netbsd.org

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=--enable-shared --with-gnu-as

USE_GMAKE=	yes
MAKE_ENV+=	BISON=true
PLIST_SRC=	${WRKSRC}/.PLIST

MAN1=		cccp.1 g++.1 g77.1 gcc.1
INFO_FILES=	cpp.info g77.info gcc.info

post-extract:
	@cd ${WRKSRC} && ${RM} -rf texinfo

post-build:
.if (${MACHINE_ARCH} != "vax")
	@cd ${WRKSRC}/libraries/libstdc++ && \
		${MAKE} piclist && \
		${AR} clq libstdc++_pic.a `cat piclist` && \
		${RANLIB} libstdc++_pic.a
.endif

post-install:
	${MV} -f ${PREFIX}/bin/${MACHINE_GNU_ARCH}--netbsd-gcc ${PREFIX}/bin/cc
	${LN} -f ${PREFIX}/bin/g77 ${PREFIX}/bin/f77
	@cd ${PREFIX}/bin && \
		strip c++ c++filt cc f77 gcov protoize unprotoize
	@cd ${PREFIX}/lib/gcc-lib/${MACHINE_GNU_ARCH}--netbsd/egcs-2.91.34 && \
		strip cc1* collect2 cpp f771
	@${CP} ${PKGDIR}/PLIST.pre ${PLIST_SRC}
.if (${MACHINE_ARCH} != "vax")
	@${ECHO} lib/libstdc++_pic.a >>${PLIST_SRC}
	${INSTALL_DATA} ${WRKSRC}/libraries/libstdc++/libstdc++_pic.a ${PREFIX}/lib/
.endif

.include "../../mk/bsd.pkg.mk"
