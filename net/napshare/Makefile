# $NetBSD: Makefile,v 1.6 2003/05/02 11:56:09 wiz Exp $

DISTNAME=	napshare-1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

DEPENDS=	gtk+>=1.2.10nb4:../../x11/gtk

USE_X11=	YES
GNU_CONFIGURE=	YES

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ARGS+=--with-gtk-prefix="${GTKDIR}"

CFLAGS+=	`${GTKDIR}/bin/gtk-config --cflags`

.include "../../mk/bsd.pkg.mk"
