# $NetBSD: Makefile,v 1.8 1998/04/21 14:23:27 hubertf Exp $
# FreeBSD Id: Makefile,v 1.26 1997/06/27 23:03:27 ache Exp 
#

V=		2.02
DISTNAME=       bash-${V}
CATEGORIES=	shells
MASTER_SITES=	ftp://slc2.ins.cwru.edu/pub/dist/  \
		${MASTER_SITE_GNU}
.if !defined(NOPORTDOCS)
DISTFILES=      bash-${V}.tar.gz bash-doc-${V}.tar.gz
.endif

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	Yes
MAN1=		bash.1 bashbug.1
USE_GTEXINFO=	yes

pre-install:
	strip ${WRKSRC}/bash

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak; ${ECHO} ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/bash-doc-${V}/doc/article.ps  \
		${WRKDIR}/bash-doc-${V}/doc/bashref.ps  \
		${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/bash-doc-${V}/doc/bash.html  \
		${WRKDIR}/bash-doc-${V}/doc/bashref.html  \
		${WRKDIR}/bash-doc-${V}/doc/bashref_toc.html  \
		${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/bash-doc-${V}/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps
.endif

.include "../../mk/bsd.pkg.mk"
