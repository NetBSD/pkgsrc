# $NetBSD: Makefile,v 1.5 2004/05/25 13:40:54 grant Exp $

MOZILLA=	thunderbird

HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client (nightly binary pkg)

MOZ_GTK2=	YES
MOZ_EXTRA=	# empty

ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	NetBSD-2.*-i386
ONLY_FOR_PLATFORM+=	SunOS-5.[789]*-sparc

.include "../../www/mozilla-bin-nightly/Makefile.common"
