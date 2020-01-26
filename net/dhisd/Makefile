# $NetBSD: Makefile,v 1.22 2020/01/26 17:31:49 rillig Exp $
#

DISTNAME=	dhisd-5.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dhis.org/
COMMENT=	DynDNS server
LICENSE=	2-clause-bsd

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin share/examples/dhisd share/doc/dhisd

SUBST_CLASSES+=		varbase
SUBST_FILES.varbase=	dhisd.h README
SUBST_STAGE.varbase=	pre-configure
SUBST_MESSAGE.varbase=	Adapt VARBASE and PREFIX
SUBST_VARS.varbase+=	VARBASE PREFIX

SPECIAL_PERMS+=		bin/dhisd-genkeys ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700 \
			bin/dhisd	  ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

do-install:
	${INSTALL_DATA} \
		${WRKSRC}/*.sample \
		${DESTDIR}${PREFIX}/share/examples/dhisd
	${INSTALL_DATA} \
		${WRKSRC}/CONTRIBUTORS  \
		${WRKSRC}/COPYRIGHT  \
		${WRKSRC}/INSTALL  \
		${WRKSRC}/README  \
		${DESTDIR}${PREFIX}/share/doc/dhisd
	${INSTALL_PROGRAM} \
		${WRKSRC}/dhisd \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} \
		${WRKSRC}/dhisgenkeys \
		${DESTDIR}${PREFIX}/bin/dhisd-genkeys

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
