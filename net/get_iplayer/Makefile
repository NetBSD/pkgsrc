# $NetBSD: Makefile,v 1.8 2016/11/18 09:58:53 jperkin Exp $

DISTNAME=	get_iplayer-2.97
CATEGORIES=	net multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=get-iplayer/}

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	https://github.com/get-iplayer/${GITHUB_PROJECT}
COMMENT=	Search, index, record or stream BBC iPlayer broadcasts
LICENSE=	gnu-gpl-v3

GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	p5-HTML-Parser>=3.0:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Cookies>=6.0:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-HTTP-Date>=6.0:../../www/p5-HTTP-Date
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-libwww>=6.0:../../www/p5-libwww
DEPENDS+=	rtmpdump>=1.8:../../net/rtmpdump
DEPENDS+=	flvstreamer>=1.8:../../multimedia/flvstreamer

USE_LANGUAGES=	# none
NO_BUILD=	yes
REPLACE_PERL=	get_iplayer

PKG_SYSCONFSUBDIR=	get_iplayer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	get_iplayer
SUBST_SED.paths=	-e "s:/etc/get_iplayer:${PKG_SYSCONFDIR}:g"
SUBST_SED.paths+=	-e "s:/usr/share/get_iplayer:${PREFIX}/share/get_iplayer:g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/get_iplayer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/get_iplayer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
