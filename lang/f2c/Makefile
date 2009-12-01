# $NetBSD: Makefile,v 1.48 2009/12/01 10:09:17 dsainty Exp $

DISTNAME=	f2c-20090411
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

CONFLICTS=	egcs-current-19980608

WRKSRC=		${WRKDIR}/f2c
USE_LIBTOOL=	yes
USE_TOOLS+=	yacc unzip

USE_BSD_MAKEFILE=	yes
MAKE_FLAGS=	LIBF2CSRCDIR='$$(.CURDIR)/libf2c' MKLTARCHIVE=yes

INSTALLATION_DIRS=	bin lib include share/doc/f2c ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1
INSTALL_MAKE_FLAGS=	BINDIR=$(PREFIX)/bin LIBDIR=$(PREFIX)/lib

post-extract:
	@${RM} ${WRKSRC}/index.html
	@cd ${WRKSRC}; ${RM} -f libf77 libi77		# subsumed by libf2c...
	@cd ${WRKSRC}; unzip -d libf2c libf2c.zip
	@cd ${WRKSRC}; ${MKDIR} libF77 libI77		# ...but we recreate them for compatibility
	@${CP} ${FILESDIR:Q}/libf77.mk ${WRKSRC}/libF77/Makefile
	@${CP} ${FILESDIR:Q}/libi77.mk ${WRKSRC}/libI77/Makefile
	@${CP} ${FILESDIR:Q}/f2c.mk ${WRKSRC}/src/Makefile
	@${CP} ${FILESDIR:Q}/libtool.mk ${WRKSRC}/libtool.mk
	@${CP} ${FILESDIR:Q}/main.mk ${WRKSRC}/Makefile
	@${CP} ${FILESDIR:Q}/f2c-f77.in ${WRKSRC}/src
	@${CP} ${FILESDIR:Q}/chktypes.c ${WRKSRC}
	@${RM} ${WRKSRC}/src/index.html
	@mv ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@mv ${WRKSRC}/src/f2c.1 ${WRKSRC}/src/f2c.1.orig

do-configure:
	@cd ${WRKSRC} && ${CC} -o chktypes chktypes.c
	${WRKSRC}/chktypes -v

# Handle f2c-f77 script:
post-build:
	${SED} -e 's;@PREFIX@;${PREFIX};g' \
	  -e 's;@CC@;${CC};g' -e 's;@CPP@;${CPP};g' \
	  -e "s;@SHELL@;${TOOLS_PLATFORM.sh:Q};g" \
	 ${FILESDIR}/f2c-f77.in > ${WRKSRC}/f2c-f77

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/f2c-f77 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/f2c.1t ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/f2c.1
	${INSTALL_DATA} ${WRKSRC}/f2c.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/f2c.0
.for f in changes f2c.ps f2c.pdf
	${INSTALL_DATA} ${WRKSRC}/$f ${DESTDIR}${PREFIX}/share/doc/f2c/$f
.endfor

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	MACHINE_ARCH=${MACHINE_ARCH:Q}


.include "../../mk/bsd.pkg.mk"
