# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:17 jlam Exp $
#

DISTNAME=	bpalogin-2.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://bpalogin.sourceforge.net/download/	\
		${MASTER_SITE_SOURCEFORGE:=bpalogin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bpalogin.sourceforge.net/
COMMENT=	BigPond Advance login client

GNU_CONFIGURE=	yes
BUILD_TARGET=	bpalogin

CONF_FILES+=	${PREFIX}/share/examples/bpalogin/bpalogin.conf \
		${PKG_SYSCONFDIR}/bpalogin.conf
RCD_SCRIPTS=	bpalogin

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpalogin ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bpalogin
	${INSTALL_DATA} ${WRKSRC}/bpalogin.conf				\
		${PREFIX}/share/examples/bpalogin

.include "../../mk/bsd.pkg.mk"
