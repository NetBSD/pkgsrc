# $NetBSD: package.mk,v 1.1 2006/08/03 18:50:32 jmmv Exp $
#

PKGNAME=	hugs98-${DISTNAME}
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/2006-05/packages/

COMMENT+=	(Hugs package)

HUGS_RUN=	${BUILDLINK_PREFIX.hugs98}/bin/runhugs
HUGS_CPPHS=	${BUILDLINK_PREFIX.hugs98}/bin/cpphs-hugs
HUGS_HSC2HS=	${BUILDLINK_PREFIX.hugs98}/bin/hsc2hs-hugs

PRINT_PLIST_AWK+=	/^@dirrm lib\/hugs\/packages$$/ \
				{ print "@comment in hugs: " $$0; next }


.include "../../lang/hugs/buildlink3.mk"

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
		install \
		--verbose
