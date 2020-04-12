# $NetBSD: Makefile,v 1.19 2020/04/12 23:59:42 joerg Exp $

DISTNAME=	get_iplayer-3.25
CATEGORIES=	net multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=get-iplayer/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/get-iplayer/${GITHUB_PROJECT}
COMMENT=	Search, index, record or stream BBC iPlayer broadcasts
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-libwww>=6.0:../../www/p5-libwww
DEPENDS+=	p5-Mojolicious>=6.0:../../www/p5-Mojolicious

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
