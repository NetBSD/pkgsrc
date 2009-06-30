# $NetBSD: Makefile,v 1.12 2009/06/30 00:07:22 joerg Exp $
#

DISTNAME=	rid-1.11
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.theorygroup.com/Software/RID/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.theorygroup.com/Software/RID/
COMMENT=	Remote Intrusion Detection to track down compromised hosts

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES

CONF_FILES=	${PREFIX}/share/examples/rid/rid.conf ${PKG_SYSCONFDIR}/rid.conf

INSTALLATION_DIRS=	sbin

post-configure:
	@echo "#undef DEFAULT_YYIN" >> ${WRKSRC}/netconfig.h
	@echo "#define DEFAULT_YYIN \"${PKG_SYSCONFDIR}/rid.conf\"" >> \
		${WRKSRC}/netconfig.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rid ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rid
	${INSTALL_DATA} ${WRKSRC}/BUGS ${WRKSRC}/CHANGES \
		${WRKSRC}/COPYRIGHT ${WRKSRC}/CREDITS ${WRKSRC}/README \
		${PREFIX}/share/doc/rid
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rid
	${INSTALL_DATA} ${WRKSRC}/rid.conf ${PREFIX}/share/examples/rid

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
