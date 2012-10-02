# $NetBSD: Makefile,v 1.62 2012/10/02 23:48:08 asau Exp $
#

DISTNAME=	rplay-3.3.2
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://rplay.doit.org/dist/

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
INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	cd ${WRKSRC}/doc; for manpage in *.[0-9]; do			\
		${SED}	-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"	\
			-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|/etc/rplay|${PKG_SYSCONFDIR}|g"		\
			$${manpage} > $${manpage}.pdone;		\
		${MV} -f $${manpage}.pdone $${manpage};			\
	done

post-install:
.for f in rplay.conf rplay.helpers rplay.hosts rplay.servers
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DESTDIR}${EGDIR}
.endfor

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
