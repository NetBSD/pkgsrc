# $NetBSD: Makefile,v 1.17 2003/01/29 11:02:58 jlam Exp $
#

BASENAME=	j2sdk
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jdk13-1
PKGREVISION=	1
COMMENT=	Linux port of the Blackdown Java(tm) Runtime Environment

DEPENDS=	blackdown-jre13>=1:../../lang/blackdown-jre13

.include "../../lang/blackdown-jre13/Makefile.common"

PLIST_SRC=	# empty
.if ${BLACKDOWN_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.i386
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

# Remove parts that are in common with the JRE.
#
post-extract:
	common=`${SED} -e "s,\\$${BLACKDOWN_ARCH},${BLACKDOWN_ARCH},g" ${FILESDIR}/common | ${AWK} '/^#.*/ { next } /^$$/ { next } { print }'`; \
	cd ${WRKSRC}; for i in $$common; do				\
		if [ -d $$i ]; then					\
			${RM} -rf $$i;					\
		else							\
			${RM} -f $$i;					\
		fi;							\
	done

.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
