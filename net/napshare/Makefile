# $NetBSD: Makefile,v 1.3 2001/11/29 01:12:42 hubertf Exp $

DISTNAME=	napshare-0.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

DEPENDS=	gtk+-1.2.*:../../x11/gtk

USE_X11=	YES
GNU_CONFIGURE=	YES

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ARGS+=--with-gtk-prefix="${GTKDIR}"

CFLAGS+=	`${GTKDIR}/bin/gtk-config --cflags`
WRKSRC=		${WRKDIR}/napshare

.include "../../mk/bsd.pkg.mk"
