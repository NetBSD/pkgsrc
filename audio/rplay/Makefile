# $NetBSD: Makefile,v 1.50 2005/12/05 20:49:49 rillig Exp $
#

DISTNAME=	rplay-3.3.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://rplay.doit.org/pub/rplay/ \
		http://rplay.doit.org/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rplay.doit.org/
COMMENT=	Network audio player

USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--build=BUILD

USE_MAKEINFO=	YES
INFO_FILES=	RPLAY.info RPTP.info librplay.info rplay.info
RCD_SCRIPTS=	rplayd
EGDIR=		${PREFIX}/share/examples/rplay

pre-configure:
	cd ${WRKSRC}/doc; for manpage in *.[0-9]; do			\
		${SED}	-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"	\
			-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|/etc/rplay|${PKG_SYSCONFDIR}|g"		\
			$${manpage} > $${manpage}.pdone;		\
		${MV} -f $${manpage}.pdone $${manpage};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
.for f in rplay.conf rplay.helpers rplay.hosts rplay.servers
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${EGDIR}
.endfor

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
