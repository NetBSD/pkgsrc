# $NetBSD: Makefile,v 1.4 1998/08/20 15:17:04 tsarna Exp $
#

DISTNAME=	egcs-19980608
CATEGORIES=	lang
MASTER_SITES=	ftp://egcs.cygnus.com/pub/egcs/snapshots/1998-06-08/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://egcs.cygnus.com/

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=--enable-shared --with-gnu-as

USE_GMAKE=	yes
MAKE_ENV+=	BISON=true
PLIST_SRC=	${WRKSRC}/.PLIST

INFO_FILES=	cpp.info g77.info gcc.info

.include "../../mk/bsd.prefs.mk"
.if defined(BOOTSTRAP_EGCS)
ALL_TARGET=	bootstrap-lean
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -rf texinfo

post-build:
# XXX this must improve.
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
	@cd ${PREFIX}/lib/gcc-lib/${MACHINE_GNU_ARCH}--netbsd/egcs-2.91.40 && \
		strip cc1* collect2 cpp f771
	@${CP} ${PKGDIR}/PLIST.pre ${PLIST_SRC}
.if (${MACHINE_ARCH} != "vax")
	@${ECHO} lib/libstdc++_pic.a >>${PLIST_SRC}
	${INSTALL_DATA} ${WRKSRC}/libraries/libstdc++/libstdc++_pic.a ${PREFIX}/lib/
.endif

.include "../../mk/bsd.pkg.mk"
