# $NetBSD: Makefile,v 1.12 2012/05/19 15:03:01 marino Exp $
#

DISTNAME=	simian_man_12_98
PKGNAME=	simian-docs-2.1
CATEGORIES=	cad
MASTER_SITES=	http://weewave.mer.utexas.edu/MED_files/MED_research/Intrcncts/SIMIAN_stuff/simian_mnl_ps_pdf/
EXTRACT_SUFX=	.pdf

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://weewave.mer.utexas.edu/MED_files/MED_research/Intrcncts/SIMIAN_stuff/simian_links.html
COMMENT=	PDF manual for SIMIAN
LICENSE=		simian-license

RESTRICTED=		Personal use only
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# http://leaf.dragonflybsd.org/mailarchive/users/2012-05/msg00066.html
NOT_FOR_PLATFORM+=	DragonFly-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/simian
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES:Q} \
		${DESTDIR}${PREFIX}/share/doc/simian

.include "../../mk/bsd.pkg.mk"
