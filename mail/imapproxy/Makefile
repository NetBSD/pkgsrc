# $NetBSD: Makefile,v 1.10 2008/03/04 17:57:18 jlam Exp $
#

DISTNAME=	imapproxy-1.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20030816021412/http://www.kuleuven.net/projects/imapproxy/
# http://www.imapproxy.org/ ?
COMMENT=	Simple connection caching IMAP proxy daemon

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapproxy ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/imapproxy
.for doc in BUGS COPYING ChangeLog FAQ INSTALL README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/imapproxy
.endfor

.include "../../mk/bsd.pkg.mk"
