# $NetBSD: Makefile,v 1.29 2001/08/27 14:35:04 tron Exp $
# FreeBSD Id: Makefile,v 1.8 1997/06/13 16:17:01 ache Exp
#

DISTNAME=	rplay-3.3.2
CATEGORIES=	audio
MASTER_SITES=	ftp://rplay.doit.org/pub/rplay/ \
		http://rplay.doit.org/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://rplay.doit.org/
COMMENT=	Network audio player

BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	RPLAY_TARGET=generic	# XXX generic, or oss, or sun?

INFO_FILES=	RPLAY.info RPTP.info librplay.info rplay.info

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

.include "../../audio/gsm/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../devel/rx/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
