# $NetBSD: Makefile,v 1.62 2012/10/02 20:11:39 asau Exp $

DISTNAME=	f2c-20100903	# see notes below
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html
COMMENT=	Fortran to C compiler including a script to emulate f77

CONFLICTS=	egcs-current-19980608

WRKSRC=		${WRKDIR}/f2c

BUILD_DIRS=	src
USE_BSD_MAKEFILE=	yes
MAKE_ENV+=		MKCATPAGES=no
INSTALLATION_DIRS=	bin share/doc/f2c ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# XXX(jmmv): This is a very ugly workaround.  CPP should probably default to
# /usr/bin/cpp in OS X.
.if ${OPSYS} == "Darwin"
F2C_F77_CPP?=	/usr/bin/cpp
.else
F2C_F77_CPP=	${CPP}
.endif

post-extract:
	@${CP} ${FILESDIR:Q}/f2c.mk ${WRKSRC}/src/Makefile
	@${CP} ${FILESDIR:Q}/gram.c ${WRKSRC}/src/gram.c
	@mv ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@mv ${WRKSRC}/src/f2c.1 ${WRKSRC}/src/f2c.1.orig

# Handle f2c-f77 script:
post-build:
	${SED} -e 's;@PREFIX@;${PREFIX};g' \
	  -e 's;@CC@;${CC};g' -e 's;@CPP@;${F2C_F77_CPP};g' \
	  -e "s;@SHELL@;${TOOLS_PLATFORM.sh:Q};g" \
	 ${FILESDIR}/f2c-f77.in > ${WRKSRC}/f2c-f77

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/f2c ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/f2c-f77 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/f2c.1t ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/f2c.1
.for f in changes f2c.ps f2c.pdf
	${INSTALL_DATA} ${WRKSRC}/$f ${DESTDIR}${PREFIX}/share/doc/f2c/$f
.endfor

# Note.  the distfile is kept locally because it is
# created "on the fly" by the real master site with
# no version number included.  This makes it difficult
# at best to use the real master site.  The distfile
# was created by:
#   ftp ftp://ftp.netlib.org/f2c.tar
#   tar -xvf f2c.tar f2c/00lastchange
#   more f2c/00lastchange
#
#read what the last change date was.
#
#   mv f2c.tar f2c-yyyymmdd.tar
#   gzip --best f2c-yyyymmdd.tar

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Werror
.endif

.include "../../mk/bsd.pkg.mk"
