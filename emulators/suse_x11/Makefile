# $NetBSD: Makefile,v 1.8 1999/10/07 17:41:52 tron Exp $

DISTNAME=		suse_x11-6.1p1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.1p1:../suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		xshared.rpm xpm.rpm

.include "../suse_linux/suse.mk"
