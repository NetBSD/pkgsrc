# $NetBSD: Makefile,v 1.6 2000/07/26 20:38:15 hubertf Exp $
# FreeBSD Id: Makefile,v 1.17 1999/04/24 09:25:32 kuriyama Exp

DISTNAME=	db155
PKGNAME=	dsssl-docbook-modular-1.55
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
DISTFILES=	db155.zip db155d.zip

MAINTAINER=	packages@netbsd.org
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
