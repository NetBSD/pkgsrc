# $NetBSD: Makefile,v 1.17 1999/03/02 03:53:07 hubertf Exp $
# FreeBSD Id: Makefile,v 1.26 1997/06/27 23:03:27 ache Exp 
#

V=		2.03
DV=		2.03
DISTNAME=       bash-${V}
CATEGORIES=	shells
MASTER_SITES=	ftp://slc2.ins.cwru.edu/pub/dist/  \
		${MASTER_SITE_GNU}/bash/

.include "../../mk/bsd.prefs.mk"

.if !defined(NOPORTDOCS)
DISTFILES=      bash-${V}.tar.gz bash-doc-${DV}.tar.gz
.endif

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html

CONFIGURE_ARGS+=--host=${MACHINE_GNU_ARCH}-unknown-netbsd --prefix=${PREFIX}
HAS_CONFIGURE=	yes
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
		${WRKDIR}/doc/article.ps  \
		${WRKDIR}/doc/bashref.ps  \
		${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/bash.html  \
		${WRKDIR}/doc/bashref.html  \
		${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps
.endif

.include "../../mk/bsd.pkg.mk"
