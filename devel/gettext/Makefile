# $NetBSD: Makefile,v 1.20 2000/11/02 00:12:29 itojun Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.10.35
PKGNAME=		gettext-0.10.35nb1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LIBINTL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"

INFO_FILES=		gettext.info

post-patch:
	${RM} -f ${WRKSRC}/intl/libgettext.h
	${RM} -f ${WRKSRC}/intl/libintl.h
	${CP} ${FILESDIR}/libgettext.h ${WRKSRC}/intl

post-configure:
	${RM} -f ${WRKSRC}/intl/libintl.h

.include "../../mk/bsd.pkg.mk"
