# $NetBSD: Makefile,v 1.27 2001/04/13 16:39:42 wiz Exp $
#

V=		2.05
DV=		2.05
DISTNAME=       bash-${V}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://slc2.ins.cwru.edu/pub/dist/
DISTFILES=      bash-${V}.tar.gz bash-doc-${DV}.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
USE_LIBINTL=	yes
MAKE_ENV+=	INSTALL_SCRIPT='${INSTALL_SCRIPT}'

.include "../../mk/bsd.prefs.mk"

.if defined(BASH_STATIC) && ${BASH_STATIC} == YES
CONFIGURE_ARGS+=	--enable-static-link
.endif

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak; ${ECHO} ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.ps  \
		${WRKDIR}/doc/bashref.ps  \
		${WRKDIR}/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bash
	${INSTALL_MAN} \
		${WRKDIR}/doc/bash.html  \
		${WRKDIR}/doc/bashref.html  \
		${PREFIX}/share/doc/html/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps

.include "../../mk/bsd.pkg.mk"
