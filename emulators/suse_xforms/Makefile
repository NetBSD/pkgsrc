# $NetBSD: Makefile,v 1.4 1999/09/19 23:58:43 tron Exp $

DISTNAME=		xforms
PKGNAME=		suse_xforms-6.1p1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=xdev1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_x11-6.1p1:../suse_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse_linux/suse.mk"
