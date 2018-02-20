# $NetBSD: Makefile,v 1.69 2018/02/20 08:43:42 dholland Exp $

DISTNAME=	rplay-3.3.2
PKGREVISION=	9
CATEGORIES=	audio
#MASTER_SITES=	http://rplay.doit.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://rplay.doit.org/
COMMENT=	Network audio player
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--build=BUILD

INFO_FILES=		yes
RCD_SCRIPTS=		rplayd
EGDIR=			${PREFIX}/share/examples/rplay
INSTALLATION_DIRS=	${EGDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc/*.[0-9]
SUBST_SED.paths=	-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"
SUBST_SED.paths+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.paths+=	-e "s|/etc/rplay/|${PKG_SYSCONFDIR}/|g"
SUBST_MESSAGE.paths=	Fixing paths in manpages.

post-install:
.for f in rplay.conf rplay.helpers rplay.hosts rplay.servers
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DESTDIR}${EGDIR}
.endfor

.include "../../audio/gsm/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
