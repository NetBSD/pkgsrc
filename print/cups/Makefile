# $NetBSD: Makefile,v 1.1.1.1 1999/11/29 02:18:53 jlam Exp $
#

DISTNAME=	cups-1.0.2-source
PKGNAME=	${DISTNAME:S/-source//}
VERS=		${PKGNAME:S/cups-//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.easysw.com/pub/cups/${VERS}/ \
		ftp://ftp2.easysw.com/pub/cups/${VERS}/ \
		ftp://ftp.northamerica.net/pub/ESP/cups/${VERS}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/cups/${VERS}/ \
		ftp://ftp.fisek.com.tr/pub/cups/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.cups.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
.for DIR in interfaces logs ppd requests
	${TOUCH} /var/cups/${DIR}/.directory
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cups
	cd ${WRKSRC}/conf; ${INSTALL_DATA} classes.conf cupsd.conf \
		cupsd.conf-personal cupsd.conf-professional mime.convs \
		mime.types printcap printers.conf \
		${PREFIX}/share/examples/cups

.include "../../mk/bsd.pkg.mk"
