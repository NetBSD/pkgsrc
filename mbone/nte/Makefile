# $NetBSD: Makefile,v 1.21 2000/09/01 17:58:05 jwise Exp $
#

DISTNAME=		nt.1.5a23
PKGNAME=		nte-1.5a23
CATEGORIES=		mbone tk80
MASTER_SITES=		http://www-mice.cs.ucl.ac.uk/multimedia/software/nte/1.5a23/

BROKEN=			This package has not yet been updated to work with tcl-8.3.2.

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www-mice.cs.ucl.ac.uk/multimedia/software/nte/

DEPENDS+=		tk-8.0.5:../../x11/tk80

NOT_FOR_PLATFORM=	*-*-alpha	# ANSI headers cause LP64 problems

RESTRICTED=		"Contains DES encryption"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

NO_WRKSUBDIR=		yes
USE_GMAKE=		yes
# Pass this on to our child

do-configure:
	cd ${WRKSRC}/netbsd && ${SH} configure

.include "../../mk/bsd.pkg.mk"

#DISGUSTING HACK ALERT
#Although nte includes an hsearch.c for those who don't have it in
# libc, there's no way to get the default Makefile to build it.
# So we build it here.
#This is below the .include "../../mk/bsd.pkg.mk" since variable names in
# targets or dependencies are evaluated when they are read so
# bsd.pkg.mk must have defined ${WRKSRC} already.
pre-build:	${WRKSRC}/netbsd/hsearch.o

${WRKSRC}/netbsd/hsearch.o:	${WRKSRC}/src/hsearch.c
	${CC} -I${WRKSRC}/src ${CFLAGS} -c -o $@ ${WRKSRC}/src/hsearch.c
