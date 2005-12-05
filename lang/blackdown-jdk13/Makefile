# $NetBSD: Makefile,v 1.24 2005/12/05 20:50:24 rillig Exp $
#

BD_BASENAME=	j2sdk
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jdk13-1
PKGREVISION=	5
COMMENT=	Linux port of the Blackdown Java(tm) Runtime Environment

DEPENDS+=	blackdown-jre13>=1:../../lang/blackdown-jre13

.include "../../lang/blackdown-jre13/Makefile.common"

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
	${LN} -sf . ${WRKSRC}/jre

.include "../../mk/bsd.pkg.mk"
