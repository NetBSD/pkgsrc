# $NetBSD: Makefile,v 1.66 2017/12/24 10:15:53 wiz Exp $

DISTNAME=	rplay-3.3.2
PKGREVISION=	7
CATEGORIES=	audio
#MASTER_SITES=	http://rplay.doit.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://rplay.doit.org/
COMMENT=	Network audio player
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--build=BUILD

INFO_FILES=	yes
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
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
