# $NetBSD: Makefile,v 1.5 2005/03/02 13:35:20 wiz Exp $
#

DISTNAME=		rinetd
PKGNAME=		${DISTNAME}-0.62
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.boutell.com/rinetd/http/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.boutell.com/rinetd/
COMMENT=		Internet redirection server

WRKSRC=			${WRKDIR}/${PKGNAME:S|nb*||}
NO_CONFIGURE=		# defined
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
