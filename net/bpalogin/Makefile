# $NetBSD: Makefile,v 1.10 2004/12/28 02:47:46 reed Exp $
#

DISTNAME=	bpalogin-2.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://bpalogin.sourceforge.net/download/	\
		${MASTER_SITE_SOURCEFORGE:=bpalogin/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bpalogin.sourceforge.net/
COMMENT=	BigPond Advance login client

GNU_CONFIGURE=	yes
BUILD_TARGET=	bpalogin

USE_PKGINSTALL=	yes
CONF_FILES+=	${PREFIX}/share/examples/bpalogin/bpalogin.conf \
		${PKG_SYSCONFDIR}/bpalogin.conf
RCD_SCRIPTS=	bpalogin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpalogin ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bpalogin
	${INSTALL_DATA} ${WRKSRC}/bpalogin.conf				\
		${PREFIX}/share/examples/bpalogin

.include "../../mk/bsd.pkg.mk"
