# $NetBSD: Makefile,v 1.25 2003/05/02 11:55:56 wiz Exp $

DISTNAME=	nxtvepg-2.5.0
PKGREVISION=	1

CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nxtvepg/}

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://sourceforge.net/projects/nxtvepg/
COMMENT=	NextView EPG decoder

ONLY_FOR_PLATFORM=      NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

USE_PERL5=	yes
USE_GMAKE=	yes
USE_X11=	yes
USE_BUILDLINK2= yes

.include "../../mk/pthread.buildlink2.mk"
PTHREAD_OPTS=native #only native threads work
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "native")
CFLAGS+=-DUSE_THREADS=1
LDFLAGS+=-pthread
MAKE_ENV+=WANT_THREADS=1
.endif


pre-configure:
	${CP} ${FILESDIR}/Makefile.netbsd ${WRKSRC}/
	cd ${WRKSRC};							\
	${MV} -f pod2help.pl pod2help.pl.orig;				\
	${SED} -e "s|@PERL5@|${PERL5}|g" pod2help.pl.orig > pod2help.pl; \
	${CHMOD} +x ${WRKSRC}/pod2help.pl

#pre-build:
#	cd ${WRKSRC};							\
#	${GMAKE} depend

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
