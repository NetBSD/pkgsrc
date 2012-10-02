# $NetBSD: Makefile,v 1.7 2012/10/02 20:11:52 asau Exp $

DISTNAME=	ruby-doc-stdlib-0.10.1
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.ruby-doc.org/downloads/stdlib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ruby-doc.org/
COMMENT=	Ruby Standard Library Documentation

NO_CONFIGURE=	yes
NO_BUILD=	yes

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
DOCDIR=		share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}
	${CP} -R ${WRKSRC}/stdlib/* ${DESTDIR}${PREFIX}/${DOCDIR}
	${FIND} ${DESTDIR}${PREFIX}/${DOCDIR} -type d -print |		\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/${DOCDIR} -type f -print |		\
		${XARGS} ${CHMOD} ${SHAREMODE}
	cd ${DESTDIR}${PREFIX} &&					\
		${FIND} ${DOCDIR} -type f -print >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
