# $NetBSD: Makefile,v 1.2 2000/09/18 18:46:27 skrll Exp $
#

DISTNAME=	nessus-libraries-${VERS}
.include 	"../nessus/Makefile.common"

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/libpeks/ltconfig \
			${WRKSRC}/libpeks/gmp3/ltconfig

# The detection of the gmp library from pkgsrc does unfortunatly not
# work. Feel free to tweak the configure script of nessus-library to
# make it find our gmp libs, I was just not able to make it work. -TF
#DEPENDS+=	gmp-*:../../devel/gmp

WRKSRC=		${WRKDIR}/nessus-libraries

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=/usr/lib
# add this to CONFIGURE_ARGS once gmp detection from pkgsrc works. -TF
#--enable-gmp=${LOCALBASE} \
#--enable-staticgmp=no

# this is needed at least for 1.5_ALPHA as for some reason the configure
# script of nessus-libraries is not able to detect our sys/socket.h. -TF
post-configure:
	${ECHO} "#define HAVE_SYS_SOCKET_H 1" >> ${WRKSRC}/include/config.h
	${ECHO} "#define HAVE_SYS_SOCKET_H 1" >> ${WRKSRC}/libpeks/peks-config.h

.include "../../mk/bsd.pkg.mk"
