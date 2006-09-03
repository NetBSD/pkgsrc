# $NetBSD: Makefile,v 1.36 2006/09/03 00:56:29 wiz Exp $
#

DISTNAME=		nt.1.5a23
PKGNAME=		nte-1.5a23
PKGREVISION=		1
CATEGORIES=		mbone tk
MASTER_SITES=		http://www-mice.cs.ucl.ac.uk/multimedia/software/nte/1.5a23/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-mice.cs.ucl.ac.uk/multimedia/software/nte/
COMMENT=		Multicast Network Text Editor

WRKSRC=			${WRKDIR}
CRYPTO=			yes
USE_TOOLS+=		gmake

# Pass this on to our child
do-configure:
	cd ${WRKSRC}/netbsd && ${SH} configure

.include "../../x11/tk83/buildlink3.mk"
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
