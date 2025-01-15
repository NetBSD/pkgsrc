# $NetBSD: Makefile,v 1.1 2025/01/15 13:28:29 manu Exp $

DISTNAME=	OpenBFDD-0.5.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dyninc/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dyninc/OpenBFDD/
COMMENT=	BFD link monitoring protocol
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++
USE_TOOLS+=	autoconf automake gmake

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes

OPENBFDD_CONFIG=	${PKG_SYSCONFDIR}/bfdd.conf
OPENBFDD_EGDIR=		${PREFIX}/share/examples

CONF_FILES=	${OPENBFDD_EGDIR}/bfdd.conf ${OPENBFDD_CONFIG}

RCD_SCRIPTS=	bfdd

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${INSTALL_DATA} ${FILESDIR}/bfdd.conf ${DESTDIR}${OPENBFDD_EGDIR}/

.include "../../mk/bsd.pkg.mk"
