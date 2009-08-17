# $NetBSD: Makefile,v 1.2 2009/08/17 14:24:32 ahoka Exp $
#

DISTNAME=		cmus-unofficial-20090605
CATEGORIES=		audio
MASTER_SITES=		http://irkmaffia.com/~replaced/dist/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		http://github.com/JasonWoof/cmus-unofficial/
COMMENT=		Curses based music player (Jason Woof's cmus fork)

CONFLICTS+=		cmus-[0-9]*
WRKSRC=			${WRKDIR}/cmus-unofficial

.include "options.mk"
.include "../cmus/Makefile.common"