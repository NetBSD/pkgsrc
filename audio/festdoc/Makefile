# $NetBSD: Makefile,v 1.1.1.1 1999/04/04 19:32:15 proff Exp $

DISTNAME=	festival-doc-1.3.1
WRKSRC=		${WRKDIR}/festdoc-1.3.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.3.1/
DISTFILES=	festdoc-1.3.1.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

NO_BUILD=	yes

FDOC=		${PREFIX}/share/doc/festival

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${FDOC}
	@ cd ${WRKSRC} && info=`find . -name '*.info*' -type f` && \
	  ${CP} $$info ${PREFIX}/info && \
	  ${CP} -r ${WRKSRC}/* ${FDOC} && \
	  cd ${FDOX} && \
	  ${RM} -f $$info

.include "../../mk/bsd.pkg.mk"
