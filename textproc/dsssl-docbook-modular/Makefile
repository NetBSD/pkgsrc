# $NetBSD: Makefile,v 1.7 2000/09/04 11:47:11 hubertf Exp $
# FreeBSD Id: Makefile,v 1.17 1999/04/24 09:25:32 kuriyama Exp

DISTNAME=	db157
PKGNAME=	dsssl-docbook-modular-1.57
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
DISTFILES=	db157.zip db157d.zip

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://nwalsh.com/docbook/dsssl/

BUILD_DEPENDS=	unzip:../../archivers/unzip
DEPENDS+=	docbook>=4.0:../../textproc/docbook

EXTRACT_CMD=	unzip ${DOWNLOADED_DISTFILE}
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/docbook

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

do-build:
	@${RM} -Rf ${WRKSRC}/docsrc

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
#	@${FIND} ${WRKDIR} -name '*~' -exec ${RM} {} \;
#	@${FIND} ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

do-install:
	@${CP} -Rp ${WRKDIR}/docbook/* ${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include "../../mk/bsd.pkg.mk"
