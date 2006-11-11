# $NetBSD: Makefile,v 1.4 2006/11/11 22:12:54 rillig Exp $

.include "Makefile.common"

DISTNAME=	foomatic-filters-ppds-${FOOMATIC_PPDS_VERSION}
PKGNAME=	${DISTNAME:S/-filters-/-/}
PKGREVISION=	1

# The definitive location of the distfile is at www.linuxprinting.org,
# but this tarball is regenerated daily from the Foomatic database.
# Rather than track this file very aggressively, we'll place a new
# copy at MASTER_SITE_LOCAL periodically and update this package
# accordingly.
#
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Foomatic PPDs collection

DEPENDS=	foomatic-filters>=3.0.2:../../print/foomatic-filters

REQD_DIRS=	share/foomatic
PLIST_SRC=	${WRKDIR}/PLIST_SRC

CHECK_PORTABILITY_SKIP=		install

do-build:
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	cd ${WRKSRC}/share;						\
	${FIND} ppd -type f -print | ${SORT} -u |			\
	${SED} -e "s|^|share/foomatic/|" >> ${PLIST_SRC}
	cd ${WRKSRC}/share;						\
	${FIND} ppd -type d -print | ${SORT} -ur |			\
	${SED} -e "s|^|@dirrm share/foomatic/|" >> ${PLIST_SRC}
	${ECHO} "@dirrm share/foomatic" >> ${PLIST_SRC}

do-install:
	${CP} -R ${WRKSRC}/share/ppd ${PREFIX}/share/foomatic/ppd

.include "../../mk/bsd.pkg.mk"
