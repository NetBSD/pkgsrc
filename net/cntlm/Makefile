# $NetBSD: Makefile,v 1.6 2020/03/20 11:58:05 nia Exp $
#

DISTNAME=	cntlm-0.35.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cntlm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cntlm.sourceforge.net/
COMMENT=	NTLM/NTLMv2 authenticating HTTP proxy
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes

CNTLM_USER?=	cntlm
CNTLM_GROUP?=	cntlm
CNTLM_CONFDIR=	${PKG_SYSCONFDIR}
PKG_USERS=	${CNTLM_USER}:${CNTLM_GROUP}
PKG_GROUPS=	${CNTLM_GROUP}

BUILD_MAKE_FLAGS+=	SYSCONFDIR=${CNTLM_CONFDIR:Q}
BUILD_TARGET=		cntlm

FILES_SUBST+=	CNTLM_USER=${CNTLM_USER:Q}
FILES_SUBST+=	PREFIX=${PREFIX:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
RCD_SCRIPTS+=	cntlm

CONF_FILES_PERMS+=	${EGDIR}/cntlm.conf ${PKG_SYSCONFDIR}/cntlm.conf \
				${CNTLM_USER} ${CNTLM_GROUP} 0600
INSTALLATION_DIRS+=	${EGDIR} ${PKGMANDIR}/man1 bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cntlm \
				${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/cntlm.1 \
				${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/cntlm.conf \
				${DESTDIR}${EGDIR}/cntlm.conf

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
