# $NetBSD: Makefile,v 1.55.6.1 2007/02/20 14:55:14 salo Exp $
#

DISTNAME=	rplay-3.3.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://rplay.doit.org/pub/rplay/ \
		http://rplay.doit.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rplay.doit.org/
COMMENT=	Network audio player

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--build=BUILD

INFO_FILES=	# PLIST
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
