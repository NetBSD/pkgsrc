# $NetBSD: Makefile,v 1.23 2000/03/30 11:56:31 wiz Exp $
# FreeBSD Id: Makefile,v 1.26 1997/06/27 23:03:27 ache Exp 
#

V=		2.04
DV=		2.04
DISTNAME=       bash-${V}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://slc2.ins.cwru.edu/pub/dist/
DISTFILES=      bash-${V}.tar.gz bash-doc-${DV}.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
MAKE_ENV+=	INSTALL_SCRIPT='${INSTALL_SCRIPT}'

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak; ${ECHO} ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
	${MKDIR} ${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.ps  \
		${WRKDIR}/doc/bashref.ps  \
		${WRKDIR}/doc/bash.html  \
		${WRKDIR}/doc/bashref.html  \
		${WRKDIR}/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps

.include "../../mk/bsd.pkg.mk"

.if defined(BASH_STATIC) && ${BASH_STATIC} == YES
CONFIGURE_ARGS+=	--enable-static-link
.endif
