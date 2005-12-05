# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:49 rillig Exp $
#

DISTNAME=		rinetd
PKGNAME=		${DISTNAME}-0.62
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.boutell.com/rinetd/http/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.boutell.com/rinetd/
COMMENT=		Internet redirection server

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=		yes
USE_PKGINSTALL=		yes
BUILD_TARGET=		rinetd

CPPFLAGS+=		-DRINETD_CONF="\"${PKG_SYSCONFDIR}/rinetd.conf\""

RCD_SCRIPTS=		rinetd

post-extract:
	@cd ${WRKDIR} && ${MV} -f rinetd ${PKGNAME:S|nb*||}

pre-build:
	@${MV} -f ${WRKSRC}/rinetd.8 ${WRKSRC}/rinetd.8.pre
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/rinetd.8.pre \
		> ${WRKSRC}/rinetd.8

.include "../../mk/bsd.pkg.mk"
