# $NetBSD: Makefile,v 1.3 2000/01/03 20:58:53 christos Exp $

DISTNAME=	mush-7.2.6.b4.pl1
CATEGORIES=	mail
MASTER_SITES=	ftp://cse.ogi.edu/pub/mush/ \
		ftp://cse.ogi.edu/pub/mush/CONTRIB/

MAINTAINER=	christos@netbsd.org

EXTRACT_ONLY=	mush-7.2.5.tar.Z
STD_PATCH_FILES=patch-7.2.6-alpha-1 \
		patch-7.2.6-alpha-2 \
		patch-7.2.6-alpha-3 \
		patch-7.2.6-beta-1 \
		patch-7.2.6-beta-2 \
		patch-7.2.6-beta-3 \
		patch-7.2.6-beta-4
DISTFILES=	${EXTRACT_ONLY} ${STD_PATCH_FILES}
DIST_SUBDIR=	mush

RESTRICTED=	"Z-Code license"
MIRROR_DISTFILE= no
NO_WRKSUBDIR=	yes

post-extract:
	@${ECHO} "===>  Applying mush-7.2.6/beta4.pl1 patches"
	@(cd ${WRKDIR}; \
	for i in ${STD_PATCH_FILES}; do \
		${PATCH} < ${_DISTDIR}/$$i; \
	done > /dev/null 2> /dev/null; \
	${RM} -f *.orig; \
	x=*.rej; \
	if [ "$$x" != '*.rej' ]; then \
		${ECHO} "Patching failed: $$x" 1>&2; \
		exit 1; \
	fi)

pre-configure:
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/config.h-dist > ${WRKSRC}/config.h
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/makefile.${LOWER_OPSYS} > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
