# $NetBSD: Makefile,v 1.19 2002/10/02 23:36:06 dillo Exp $

DISTNAME=		nut-0.50.0
PKGNAME=		ups-nut-cgi-0.50.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/

MAINTAINER=		lukem@netbsd.org
HOMEPAGE=		http://www.exploits.org/nut/
COMMENT=		Network UPS Tools CGI scripts

DEPENDS+=		ups-nut-0.*:../../sysutils/ups-nut

ALL_TARGET=		cgi
INSTALL_TARGET=		install-cgi install-cgi-man

PKG_SYSCONFSUBDIR?=	nut
NUT_CONFDIR=		${PKG_SYSCONFDIR}
NUT_STATEDIR=		/var/db/nut
NUT_CGIDIR=		${PREFIX}/share/nut/cgi

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR}			\
			--with-statepath=${NUT_STATEDIR}		\
			--with-cgipath=${NUT_CGIDIR}			\
			--with-graphics=${LOCALBASE}

.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
