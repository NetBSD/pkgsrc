# $NetBSD: Makefile,v 1.37 2004/10/03 00:13:00 tv Exp $

DISTNAME=	nxtvepg-2.6.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nxtvepg/}

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://sourceforge.net/projects/nxtvepg/
COMMENT=	NextView EPG decoder

ONLY_FOR_PLATFORM=      NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-* \
			NetBSD-[2-9]*-*

USE_PERL5=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes
USE_BUILDLINK3= yes

.include "../../mk/pthread.buildlink3.mk"

# Only native threads work.
.if ${PTHREAD_TYPE} == "native"
CFLAGS+=	-DUSE_THREADS=1
MAKE_ENV+=	WANT_THREADS=1
.endif
# Required for Tcl/Tk 8.4
LDFLAGS+=	${PTHREAD_LDFLAGS}

pre-configure:
	cd ${WRKSRC};							\
	${MV} -f pod2help.pl pod2help.pl.orig;				\
	${SED} -e "s|@PERL5@|${PERL5}|g" pod2help.pl.orig > pod2help.pl; \
	${CHMOD} +x ${WRKSRC}/pod2help.pl

#pre-build:
#	cd ${WRKSRC};							\
#	${GMAKE} depend

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
