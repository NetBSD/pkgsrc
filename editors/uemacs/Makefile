# $NetBSD: Makefile,v 1.13 2012/05/10 20:53:30 dholland Exp $

DISTNAME=	ue400dev
PKGNAME=	uemacs-4.0
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://aquest.com/pub/uemacs400/disk2/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	"emacs" key sequences compatible full screen editor

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin share/uemacs

WRKSRC=		${WRKDIR}
EXTRACT_OPTS_ZIP=	-Laqo

post-extract:
	${CP} -r ${WRKSRC}/freebsd ${WRKSRC}/netbsd

post-patch:
	for FILE in ${WRKSRC}/src/*.c ${WRKSRC}/h/*.h; do \
	  ${MV} $${FILE} $${FILE}.old; \
	  ${SED} -e "s|%%PREFIX%%|${PREFIX}|g" <$${FILE}.old >$${FILE}; \
	done

.include "../../mk/bsd.pkg.mk"
