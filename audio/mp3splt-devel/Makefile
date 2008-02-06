# $NetBSD: Makefile,v 1.1.1.1 2008/02/06 09:31:06 bjs Exp $
#

DISTNAME=		mp3splt-2.2_rc1
PKGNAME=		${DISTNAME:S/_//}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mp3splt.sourceforge.net/
COMMENT=		Command line utility to split MP3 (VBR supported) and OGG files

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		mp3splt-[0-9]*

GNU_CONFIGURE=	 	yes
USE_PKGLOCALEDIR=	yes
USE_FEATURES= 	 	getopt_long

.include "../../mk/bsd.prefs.mk"
###
### This was done in configure, but best to do it here--the tests are
### not robust.
###
.if ${OPSYS} == "Solaris"
LIBS+= 	 -lsocket
.endif

post-install:
	${LN} -s ${DESTDIR}${PREFIX}/bin/mp3splt \
 	 	${DESTDIR}${PREFIX}/bin/oggsplt

.include "../../audio/libmp3splt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
