# $NetBSD: Makefile,v 1.1.1.1 1999/06/27 14:25:18 drochner Exp $
# FreeBSD Id: Makefile,v 1.17 1999/04/24 09:25:32 kuriyama Exp

DISTNAME=	db141
PKGNAME=	dsssl-docbook-modular-1.41
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
DISTFILES=	db141.zip db141d.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://nwalsh.com/docbook/dsssl/

BUILD_DEPENDS=	unzip:../../archivers/unzip
DEPENDS+=	docbook-3.1:../../textproc/docbook

EXTRACT_CMD=	unzip ${DOWNLOADED_DISTFILE}
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/docbook

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

do-build:
	@${RM} -Rf ${WRKSRC}/docsrc

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
#	@find ${WRKDIR} -name '*~' -exec ${RM} {} \;
#	@find ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

do-install:
	@${CP} -Rp ${WRKDIR}/docbook/* ${INSTDIR}
	@$(CHOWN) -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include <../../mk/bsd.pkg.mk>
