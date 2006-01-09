# $NetBSD: Makefile,v 1.10 2006/01/09 23:39:09 joerg Exp $
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
BUILD_TARGET=		rinetd

CPPFLAGS+=		-DRINETD_CONF="\"${PKG_SYSCONFDIR}/rinetd.conf\""

RCD_SCRIPTS=		rinetd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	rinetd.8
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	@cd ${WRKDIR} && ${MV} -f rinetd ${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
