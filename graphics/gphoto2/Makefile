# $NetBSD: Makefile,v 1.5 2001/11/29 01:12:35 hubertf Exp $

DISTNAME=	gphoto-2.0beta1
PKGNAME=	gphoto-2.0.0.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gphoto.org/gphoto2/
COMMENT=	Download and view files from various digital cameras

BUILD_USES_MSGFMT=	yes

USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
#LIBTOOL_OVERRIDE=	yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/build.sh
CONFIGURE_ARGS+=	--with-html-dir=${LOCALBASE}/share/doc/html/gphoto2
.include "../../devel/gettext-lib/buildlink.mk"

post-patch:
	${RM} -f ${LTCONFIG_OVERRIDE} ;                         \
	${ECHO} "${RM} -f libtool; ${LN} -s ${LIBTOOL} libtool" \
	        > ${LTCONFIG_OVERRIDE} ;                        \
	${CHMOD} +x ${LTCONFIG_OVERRIDE} ;                      \

pre-configure:
	for i in `find ${WRKSRC} -name Makefile.in`;		\
	do							\
		${CP} $$i $$i.NB;				\
		${SED} -e 's/\/\.libs//g' < $$i.NB > $$i;		\
	done							\

.include "../../devel/glib/buildlink.mk"
.include "../../devel/libusb/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
