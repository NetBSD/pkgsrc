# $NetBSD: Makefile,v 1.51 2009/12/20 12:27:57 jmmv Exp $

DISTNAME=	f2c-20090411	# see notes below
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html
COMMENT=	Fortran to C compiler including a script to emulate f77

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	egcs-current-19980608

WRKSRC=		${WRKDIR}/f2c

BUILD_DIRS=	src
USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		yacc
INSTALLATION_DIRS=	bin share/doc/f2c ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

.include "../../mk/bsd.prefs.mk"

# XXX(jmmv): This is a very ugly workaround.  CPP should probably default to
# /usr/bin/cpp in OS X.
.if ${OPSYS} == "Darwin"
F2C_F77_CPP=	/usr/bin/cpp
.else
F2C_F77_CPP=	${CPP}
.endif

post-extract:
	@${CP} ${FILESDIR:Q}/f2c.mk ${WRKSRC}/src/Makefile
	@mv ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@mv ${WRKSRC}/src/f2c.1 ${WRKSRC}/src/f2c.1.orig

# Handle f2c-f77 script:
post-build:
	${SED} -e 's;@PREFIX@;${PREFIX};g' \
	  -e 's;@CC@;${CC};g' -e 's;@CPP@;${F2C_F77_CPP};g' \
	  -e "s;@SHELL@;${TOOLS_PLATFORM.sh:Q};g" \
	 ${FILESDIR}/f2c-f77.in > ${WRKSRC}/f2c-f77

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/f2c-f77 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/f2c.1t ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/f2c.1
	${INSTALL_DATA} ${WRKSRC}/f2c.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/f2c.0
.for f in changes f2c.ps f2c.pdf
	${INSTALL_DATA} ${WRKSRC}/$f ${DESTDIR}${PREFIX}/share/doc/f2c/$f
.endfor

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

.include "../../mk/bsd.pkg.mk"
