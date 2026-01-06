# $NetBSD: Makefile,v 1.8 2026/01/06 17:10:34 ryoon Exp $
#

DISTNAME=	multiskkserv-20240224
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=sina-ht/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	${PKGBASE}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/sina-ht/multiskkserv/
COMMENT=	Simple skk multi-dictionary server
LICENSE=	gnu-gpl-v2

DEPENDS=	skk-jisyo-cdb>=20240117:../../inputmethod/skk-jisyo-cdb

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOCSDIR}

INSTALL_DOCS=		README \
			README.j

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	multiskkserv

post-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}/${DOCSDIR}
.endfor

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's/-D_REENTRANT/${PTHREAD_CFLAGS}/g'
SUBST_SED.pthread+=	-e 's/-lpthread/${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}/g'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
