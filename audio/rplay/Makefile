# $NetBSD: Makefile,v 1.25 2001/05/01 07:16:14 jlam Exp $
# FreeBSD Id: Makefile,v 1.8 1997/06/13 16:17:01 ache Exp
#

DISTNAME=	rplay-3.3.2
CATEGORIES=	audio
MASTER_SITES=	ftp://rplay.doit.org/pub/rplay/ \
		http://rplay.doit.org/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://rplay.doit.org/
COMMENT=	Network audio player

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

DEPENDS+=	gsm-1.0.10:../../audio/gsm
DEPENDS+=	rx-1.5:../../devel/rx

USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	RPLAY_TARGET=generic	# XXX generic, or oss, or sun?
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include	# for gsm.h and rxposix.h

.if !exists(/usr/include/readline.h) && \
    !exists(/usr/include/readline/readline.h)
DEPENDS+=	readline>=4.0:../../devel/readline
.endif

INFO_FILES=	RPLAY.info RPLAY.info librplay.info rplay.info

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf
	cd ${WRKSRC}/doc; for f in *.[0-9]; do				\
		${SED} -e "s|/usr/local|${PREFIX}|g" $$f > $$f.pdone;	\
		${MV} -f $$f.pdone $$f;					\
	done

post-install:
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/rplayd.sh > ${WRKDIR}/rplayd.sh
	${INSTALL_SCRIPT} ${WRKDIR}/rplayd.sh ${PREFIX}/etc/rc.d/rplayd
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
