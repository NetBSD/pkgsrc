# $NetBSD: Makefile,v 1.32 2001/11/25 18:59:45 jlam Exp $
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
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		RPLAY_TARGET=generic	# XXX generic, or oss, or sun?

INFO_FILES=	RPLAY.info RPTP.info librplay.info rplay.info
RCD_SCRIPTS=	rplayd

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf --force
	cd ${WRKSRC}/doc; for manpage in *.[0-9]; do			\
		${SED}	-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"	\
			-e "s|/usr/local|${PREFIX}|g"			\
			$${manpage} > $${manpage}.pdone;		\
		${MV} -f $${manpage}.pdone $${manpage};			\
	done

post-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/rplayd.sh > ${WRKDIR}/rplayd
	${INSTALL_SCRIPT} ${WRKDIR}/rplayd ${PREFIX}/etc/rc.d/rplayd
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../audio/gsm/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../devel/rx/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
