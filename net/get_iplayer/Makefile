# $NetBSD: Makefile,v 1.4 2015/01/17 12:33:14 prlw1 Exp $

DISTNAME=	get_iplayer-2.91
CATEGORIES=	net multimedia
MASTER_SITES=	ftp://ftp.infradead.org/pub/get_iplayer/

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://www.infradead.org/get_iplayer/html/get_iplayer.html
COMMENT=	Search, index, record or stream BBC iPlayer broadcasts
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-HTML-Parser>=3.0:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Cookies>=6.0:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-HTTP-Date>=6.0:../../www/p5-HTTP-Date
DEPENDS+=	p5-libwww>=6.0:../../www/p5-libwww
DEPENDS+=	rtmpdump>=1.8:../../net/rtmpdump
DEPENDS+=	flvstreamer>=1.8:../../multimedia/flvstreamer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_LANGUAGES=	# none
NO_BUILD=	yes
REPLACE_PERL=	get_iplayer

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fixup config and plugin paths
SUBST_FILES.prefix=	get_iplayer
SUBST_SED.prefix=	-e s:@PREFIX@:${PREFIX}:

PKG_SYSCONFSUBDIR=	get_iplayer
EGDIR=			${PREFIX}/share/examples/get_iplayer
CONF_FILES=		${EGDIR}/options ${PKG_SYSCONFDIR}/options
INSTALLATION_DIRS+=	${EGDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/get_iplayer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/get_iplayer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${FILESDIR}/options.default ${DESTDIR}${EGDIR}/options

.include "../../mk/bsd.pkg.mk"
