# $NetBSD: Makefile,v 1.2 2005/04/11 21:47:21 tv Exp $

DISTNAME=	scponly-4.0
CATEGORIES=	shells security
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.sublimation.org/scponly/
COMMENT=	Tiny shell that only permits scp and sftp

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_PKGINSTALL=		yes
PKG_SHELL=		${PREFIX}/bin/scponly
PKG_SYSCONFSUBDIR=	scponly

EGDIR=		${PREFIX}/share/examples/scponly
CONF_FILES=	${EGDIR}/debuglevel ${PKG_SYSCONFDIR}/debuglevel

.include "../../mk/bsd.pkg.mk"
