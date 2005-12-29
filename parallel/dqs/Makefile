# $NetBSD: Makefile,v 1.6 2005/12/29 06:22:05 jlam Exp $
#

DISTNAME=	DQS-3.3.2
PKGNAME=	dqs-3.3.2
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scri.fsu.edu/~pasko/dqs.html
COMMENT=	Distributed queueing system

WRKSRC=		${WRKDIR}/DQS3
DOCDIR=		${PREFIX}/share/doc/dqs
DOCS=		Image16.gif Image17.gif Image18.gif Image19.gif Image20.gif \
		Image21.gif Image22.gif Image23.gif InstMaint.html \
		Refernce.html UserGuide.html error_msg.htm

EGDIR=		${PREFIX}/share/examples/dqs

# PKG_SYSCONFSUBDIR?=dqs
# CONF_FILES+=	${EGDIR}/conf_file ${PKG_SYSCONFDIR}/conf_file
# CONF_FILES+=	${EGDIR}/key_file ${PKG_SYSCONFDIR}/key_file
# CONF_FILES+=	${EGDIR}/resolve_file ${PKG_SYSCONFDIR}/resolve_file

post-patch:
	${ECHO} '#undef DEFAULT_HOST' >> ${WRKSRC}/SRC/dqs.h

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/DOC/user_guide/${doc} ${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
