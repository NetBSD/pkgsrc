# $NetBSD: Makefile,v 1.3 2011/11/17 19:37:51 ryoon Exp $
#

DISTNAME=	multiskkserv-20100128-ac
PKGNAME=	${DISTNAME:S/-ac//}
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://github.com/sina-ht/multiskkserv/
COMMENT=	Simple skk multi-dictionary server
LICENSE=	gnu-gpl-v2

DEPENDS=	skk-jisyo-cdb-[0-9]*:../../inputmethod/skk-jisyo-cdb

PKG_DESTDIR_SUPPORT=	user-destdir

FIND_PREFIX:=		SKKJISYOCDBDIR=skk-jisyo-cdb

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOCSDIR}

INSTALL_DOCS=		README \
			README.j

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	multiskkserv

FILES_SUBST=	SKKJISYOCDBDIR=${SKKJISYOCDBDIR}

post-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}/${DOCSDIR}
.endfor

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's/-D_REENTRANT/${PTHREAD_CFLAGS}/g'
SUBST_SED.pthread+=	-e 's/-lpthread/${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}/g'

.include "../../mk/find-prefix.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
