# $NetBSD: Makefile,v 1.7 2005/05/22 20:07:37 jlam Exp $
#

DISTNAME=	darkice-0.14
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=darkice/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://darkice.sourceforge.net/
COMMENT=	IceCast, IceCast2 and ShoutCast live audio streamer

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis}
CONFIGURE_ARGS+=	--with-lame-prefix=${BUILDLINK_PREFIX.lame}
LIBS+=			${LIBOSSAUDIO}

EGDIR=		${PREFIX}/share/examples/darkice
HTMLDIR=	${PREFIX}/share/doc/html/darkice

CONF_FILES=	${EGDIR}/darkice.conf.default ${PKG_SYSCONFDIR}/darkice.conf

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/darkice.cfg ${EGDIR}/darkice.conf.default
	${INSTALL_PROGRAM} ${WRKSRC}/src/darkice ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/darkice.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/darkice.cfg.5 \
		${PREFIX}/man/man5/darkice.conf.5
	for f in ${WRKSRC}/kdoc/*.html; do \
		${INSTALL_DATA} $$f ${HTMLDIR}; \
	done

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
