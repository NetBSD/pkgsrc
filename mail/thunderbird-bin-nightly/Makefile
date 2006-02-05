# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:59 joerg Exp $

MOZILLA=	thunderbird
PKGREVISION=	1

HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client (nightly binary pkg)

MOZ_GTK2=	YES
MOZ_EXTRA=	# empty

ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	NetBSD-2.*-i386
ONLY_FOR_PLATFORM+=	SunOS-5.[789]*-sparc

.include "../../www/mozilla-bin-nightly/Makefile.common"
