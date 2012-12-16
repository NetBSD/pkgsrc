# $NetBSD: Makefile,v 1.20 2012/12/16 01:52:01 obache Exp $
#

DISTNAME=		rss2html-0.8.2
PKGREVISION=		4
CATEGORIES=		converters
MASTER_SITES=		ftp://ftp.nopcode.org/prj/rss2html/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nopcode.org/blog/rss2html.html
COMMENT=		RSS to HTML converter

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/rss2html

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LIBS=${LIBS:M*:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rss2html ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/rss2html.links ${DESTDIR}${PREFIX}/share/doc/rss2html/
	${INSTALL_DATA} ${WRKSRC}/doc/usage.example ${DESTDIR}${PREFIX}/share/doc/rss2html/
	${INSTALL_DATA} ${WRKSRC}/doc/rss2html.template ${DESTDIR}${PREFIX}/share/doc/rss2html/
	${INSTALL_DATA} ${WRKSRC}/README	${DESTDIR}${PREFIX}/share/doc/rss2html/
	${INSTALL_MAN} ${WRKSRC}/doc/rss2html.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
