# $NetBSD: Makefile,v 1.4 2001/09/27 23:18:39 jlam Exp $
#

DISTNAME=	nessus-libraries-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/libpeks/ltconfig \
			${WRKSRC}/libpeks/gmp3/ltconfig

# The detection of the gmp library from pkgsrc does unfortunatly not
# work. Feel free to tweak the configure script of nessus-library to
# make it find our gmp libs, I was just not able to make it work. -TF
#DEPENDS+=	gmp-[0-9]*:../../devel/gmp

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
