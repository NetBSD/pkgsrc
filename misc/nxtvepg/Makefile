# $NetBSD: Makefile,v 1.75 2022/06/28 11:34:49 wiz Exp $

DISTNAME=	nxtvepg-2.7.6
PKGREVISION=	18
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nxtvepg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/nxtvepg/
COMMENT=	NextView EPG decoder

MAKE_JOBS_SAFE=	no

ONLY_FOR_PLATFORM=	NetBSD-*-*

USE_TOOLS+=	gmake perl:run
DEPENDS+=	p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

# Only native threads work.
.if ${PTHREAD_TYPE} == "native"
CFLAGS+=	-DUSE_THREADS=1
MAKE_ENV+=	WANT_THREADS=1
.endif
# Required for Tcl/Tk 8.4
LDFLAGS+=	${PTHREAD_LIBS}

INSTALL_MAKE_FLAGS+=	ROOT=${DESTDIR} resdir=${DESTDIR}${PREFIX}/lib/X11

pre-configure:
	cd ${WRKSRC};							\
	${MV} -f pod2help.pl pod2help.pl.orig;				\
	${SED} -e "s|@PERL5@|${PERL5}|g" pod2help.pl.orig > pod2help.pl; \
	${CHMOD} +x ${WRKSRC}/pod2help.pl

#pre-build:
#	cd ${WRKSRC};							\
#	${GMAKE} depend

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
