# $NetBSD: package.mk,v 1.6 2016/04/10 16:39:27 joerg Exp $
#

PKGNAME=	hugs98-${DISTNAME}
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/2006-09/packages/

COMMENT+=	(Hugs package)

HUGS_RUN=	${BUILDLINK_PREFIX.hugs98}/bin/runhugs
HUGS_CPPHS=	${BUILDLINK_PREFIX.hugs98}/bin/cpphs-hugs
HUGS_HSC2HS=	${BUILDLINK_PREFIX.hugs98}/bin/hsc2hs-hugs

.include "../../lang/hugs/buildlink3.mk"

.include "../../mk/bsd.fast.prefs.mk"

do-configure:
	cd ${WRKSRC} && ${HUGS_RUN} -98 Setup.hs \
		configure \
		--verbose \
		--prefix=${PREFIX:Q} \
		--hugs \
		--with-cpphs=${HUGS_CPPHS:Q} \
		--with-hsc2hs=${HUGS_HSC2HS:Q}

do-build:
	cd ${WRKSRC} && ${HUGS_RUN} -98 Setup.hs \
		build \
		--verbose

do-install:
	cd ${WRKSRC} && ${HUGS_RUN} -98 Setup.hs \
		copy --verbose --destdir=${DESTDIR}
	cd ${WRKSRC} && \
	pkg=`awk '{ print $$2; nextfile }' < .installed-pkg-config` && \
	${ECHO} $$pkg && \
	${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/lib/hugs/packages/$$pkg/packages/$$pkg && \
	${INSTALL_DATA} .installed-pkg-config \
	    ${DESTDIR}${PREFIX}/lib/hugs/packages/$$pkg/packages/$$pkg/package.conf
