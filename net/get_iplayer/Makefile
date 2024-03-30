# $NetBSD: Makefile,v 1.25 2024/03/30 09:26:53 abs Exp $

DISTNAME=	get_iplayer-3.34
PKGREVISION=	1
CATEGORIES=	net multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=get-iplayer/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/get-iplayer/get_iplayer
COMMENT=	Search, index, record or stream BBC iPlayer broadcasts
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https
DEPENDS+=	p5-Mojolicious>=6.0:../../www/p5-Mojolicious
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-libwww>=6.0:../../www/p5-libwww

USE_LANGUAGES=	# none
NO_BUILD=	yes
REPLACE_PERL=	get_iplayer

PKG_SYSCONFSUBDIR=	get_iplayer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	get_iplayer
SUBST_SED.paths=	-e "s:/etc/get_iplayer:${PKG_SYSCONFDIR}:g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/get_iplayer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/get_iplayer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
