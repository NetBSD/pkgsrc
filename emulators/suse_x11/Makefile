# $NetBSD: Makefile,v 1.9 2000/01/09 07:11:31 tls Exp $

DISTNAME=		suse_x11-6.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.3:../suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		xshared.rpm xpm.rpm

.include "../suse_linux/suse.mk"
