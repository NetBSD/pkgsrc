# $NetBSD: Makefile,v 1.14 2008/06/20 01:09:29 joerg Exp $
#

DISTNAME=	bpalogin-2.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://bpalogin.sourceforge.net/download/	\
		${MASTER_SITE_SOURCEFORGE:=bpalogin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bpalogin.sourceforge.net/
COMMENT=	BigPond Advance login client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
BUILD_TARGET=	bpalogin

CONF_FILES+=	${PREFIX}/share/examples/bpalogin/bpalogin.conf \
		${PKG_SYSCONFDIR}/bpalogin.conf
RCD_SCRIPTS=	bpalogin

INSTALLATION_DIRS=	sbin share/examples/bpalogin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpalogin ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/bpalogin.conf				\
	    ${DESTDIR}${PREFIX}/share/examples/bpalogin

.include "../../mk/bsd.pkg.mk"
