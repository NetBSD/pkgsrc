# $NetBSD: Makefile,v 1.1.1.1 1999/09/15 18:56:20 jlam Exp $
#

DISTNAME=	isect-1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://home.netcom.com/pub/users/tgagne/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://home.netcom.com/~tgagne/

DEPENDS+=	libwww-5.1m1:../../www/libwww

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include	# for w3c-libwww/WWWlib.h
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

DOCDIR=		${PREFIX}/share/doc/isect
EGDIR=		${PREFIX}/share/examples/isect

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ${WRKSRC}/doc/*.html; do \
		${INSTALL_DATA} $${file} ${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/workers/isdecho.c ${EGDIR}

	${SED}	-e "s#@PREFIX@#${PREFIX}#g" \
		-e "s#@ECHO@#${ECHO}#g" \
		${FILESDIR}/isect.sh > ${WRKDIR}/isect.sh
	${INSTALL_SCRIPT} ${WRKDIR}/isect.sh ${PREFIX}/etc/rc.d/

	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
