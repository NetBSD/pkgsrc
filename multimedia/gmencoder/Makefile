# $NetBSD: Makefile,v 1.27 2006/09/16 12:20:39 jmmv Exp $
#

DISTNAME=	gmencoder-0.1.0
PKGREVISION=	19
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gmencoder/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmencoder.sourceforge.net/
COMMENT=	GNOME2 frontend to mencoder

BROKEN_IN=		pkgsrc-2006Q1

DEPENDS+=       	mencoder>=0.90:../../multimedia/mencoder
DEPENDS+=       	mplayer>=0.90:../../multimedia/mplayer

GNU_CONFIGURE=		yes
USE_DIRS+=       	gnome2-1.5
USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
EGDIR=			${PREFIX}/share/examples/gmencoder
CONF_FILES=		${EGDIR}/gmencoder_opts ${PKG_SYSCONFDIR}/gmencoder_opts

post-build:
	${MV} ${WRKSRC}/etc/gmencoder_opts ${WRKSRC}/etc/gmencoder_opts.in
	${SED} -e 's|/usr/local|${PREFIX}|g' \
		< ${WRKSRC}/etc/gmencoder_opts.in > ${WRKSRC}/etc/gmencoder_opts

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/gmencoder_opts ${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
