# $NetBSD: Makefile,v 1.43 2007/12/16 15:47:55 gdt Exp $

DISTNAME=	f2c-20001205
PKGREVISION=	9
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

# Note.  the distfile is kept locally because it is
# created "on the fly" by the real master site with
# no version number included.  This makes it difficult
# at best to use the real master site.  The distfile
# was created by:
#   ftp ftp://netlib.bell-labs.com/netlib/f2c.tar
#   tar -xvf f2c.tar f2c/00lastchange.gz
#   gzcat f2c/00lastchange.gz
#
#read what the last change date was.
#
#   mv f2c.tar f2c-yyyymmdd.tar
#   gzip --best f2c-yyyymmdd.tar
MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html
COMMENT=	Fortran to C compiler including a script to emulate f77

PKG_DESTDIR_SUPPORT=	user-destdir

# Many failures - this is *very* far from safe.
MAKE_JOBS_SAFE=		no

CONFLICTS=	egcs-current-19980608

F2CMAJOR=	0
F2CMINOR=	0
MAKE_ENV+=	F2CMAJOR=${F2CMAJOR:Q} F2CMINOR=${F2CMINOR:Q}
MAKE_ENV+=	LIBOWN=${LIBOWN:Q} LIBGRP=${LIBGRP:Q}
MAKE_ENV+=	AWK=${AWK:Q}
MAKE_ENV+=	ECHO=${ECHO:Q}
MAKE_ENV+=	F2C_F77_IN=${FILESDIR:Q}/f2c-f77.in
MAKE_ENV+=	SCRIPT_SHELL=${TOOLS_PLATFORM.sh:Q}
WRKSRC=		${WRKDIR}/f2c
USE_LIBTOOL=	yes
USE_TOOLS+=	gunzip

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

# work around a problem gunzipping 00lastchange.gz with
# some versions of zlib found on NetBSD and also Gentoo
post-extract:
	@${RM} ${WRKSRC}/index.html
	@for f in ${WRKSRC}/*.gz ; do \
		if ${TEST} "$$f" = "${WRKSRC}/00lastchange.gz" ; then \
			${ECHO} "Skipping $$f" ; \
		else \
			${GUNZIP_CMD} $$f ; \
		fi ; \
	done
	@mv ${WRKSRC}/libf77 ${WRKSRC}/libf77.sh
	@mv ${WRKSRC}/libi77 ${WRKSRC}/libi77.sh
	@cd ${WRKSRC} ; ${SH} libf77.sh ; ${SH} libi77.sh
	@${RM} ${WRKSRC}/src/index.html
	@mv ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@${GUNZIP_CMD} ${WRKSRC}/src/*.gz

do-configure:
	@cd ${WRKSRC} && ${CC} -o chktypes chktypes.c
	${WRKSRC}/chktypes -v
	@${CP} -f ${WRKSRC}/libF77/signal1.h0 ${WRKSRC}/libF77/signal1.h
	@${CP} -f ${WRKSRC}/f2c.h ${WRKSRC}/libF77/f2c.h
	@${CP} -f ${WRKSRC}/f2c.h ${WRKSRC}/libI77/f2c.h

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	MACHINE_ARCH=${MACHINE_ARCH:Q}


.include "../../mk/bsd.pkg.mk"
