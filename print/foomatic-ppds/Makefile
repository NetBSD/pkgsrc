# $NetBSD: Makefile,v 1.13 2023/07/03 12:51:21 wiz Exp $

.include "Makefile.common"

DISTNAME=	foomatic-filters-ppds-${FOOMATIC_PPDS_VERSION}
PKGNAME=	${DISTNAME:S/-filters-/-/}

# The definitive location of the distfile is at www.linuxprinting.org,
# but this tarball is regenerated daily from the Foomatic database.
# Rather than track this file very aggressively, we'll place a new
# copy at MASTER_SITE_LOCAL periodically and update this package
# accordingly.
#
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITES+=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foomatic PPDs collection

DEPENDS=	foomatic-filters>=3.0.2<4:../../print/foomatic-filters

REQD_DIRS=	share/foomatic

CHECK_PORTABILITY_SKIP=		install

GENERATE_PLIST+=							\
	( cd ${WRKSRC}/share;						\
	  ${FIND} ppd -type f -print | ${SORT} -u |			\
	  ${SED} -e "s|^|share/foomatic/|" );

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/foomatic

do-install:
	${CP} -R ${WRKSRC}/share/ppd ${DESTDIR}${PREFIX}/share/foomatic

.include "../../mk/bsd.pkg.mk"
