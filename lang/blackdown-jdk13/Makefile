# $NetBSD: Makefile,v 1.16 2002/11/25 14:08:22 schmonz Exp $
#

BASENAME=	j2sdk
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jdk13-1
PKGREVISION=	1
COMMENT=	Linux port of the Blackdown Java(tm) Runtime Environment

DEPENDS=	blackdown-jre13>=1:../../lang/blackdown-jre13

.include "../../lang/blackdown-jre13/Makefile.common"

PLIST_SRC=	${PKGDIR}/PLIST
.if ${BLACKDOWN_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.i386
.endif

# these are part of JRE
post-extract:
	cd ${WRKSRC}/jre/bin;						\
	for i in * .java_wrapper; do					\
		if [ -f $$i ]; then					\
			${RM} -f $$i ${WRKSRC}/bin/$$i;			\
		else							\
			${RM} -rf $$i;					\
		fi							\
	done
	${RM} -rf ${WRKSRC}/jre
	${RM} -f ${WRKSRC}/LICENSE ${WRKSRC}/CHANGES			\
		${WRKSRC}/COPYRIGHT ${WRKSRC}/README ${WRKSRC}/INSTALL

.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
